/**
 * The µkleos scheduler implementation
 *
 * Copyright (C) 2010 Freie Universität Berlin
 *
 * This file subject to the terms and conditions of the GNU General Public
 * License. See the file LICENSE in the top level directory for more details.
 *
 * @ingroup kernel
 * @{
 * @file
 * @author Kaspar Schleiser <kaspar.schleiser@fu-berlin.de>
 * @}
 */

#include <stdint.h>
#include <malloc.h>
#include "sched.h"
#include "kernel.h"
#include "kernel_intern.h"
#include "clist.h"
#include <bitarithm.h>

//#define ENABLE_DEBUG
#include "debug.h"

volatile int num_tasks = 0;

clist_node_t *runqueues[SCHED_PRIO_LEVELS];
static uint32_t runqueue_bitcache = 0;

#if SCHEDSTATISTICS
    schedstat pidlist[MAXTHREADS];
#endif

void sched_init() {
    printf("Scheduler...");
    int i;
    for (i=0; i<MAXTHREADS; i++) {
        sched_threads[i] = NULL;
#if SCHEDSTATISTICS
        pidlist[i].laststart = 0;
        pidlist[i].runtime = 0;
        pidlist[i].schedules = 0;
#endif
    }

    active_thread = NULL;
    thread_pid = -1;
    for (i = 0; i < SCHED_PRIO_LEVELS; i++) {
        runqueues[i] = NULL;
    }

    printf("[OK]\n");
}

void sched_run() {
    sched_context_switch_request = 0;

    tcb *my_active_thread = (tcb*)active_thread;

    if (my_active_thread) {
        if( my_active_thread->status ==  STATUS_RUNNING) {
            my_active_thread->status =  STATUS_PENDING;
        }

#ifdef SCHED_TEST_STACK
        if (*((unsigned int*)my_active_thread->stack_start) != (unsigned int) my_active_thread->stack_start) {
            printf("scheduler(): stack overflow detected, task=%s pid=%u\n", my_active_thread->name, my_active_thread->pid);
        }
#endif

    }

#if SCHEDSTATISTICS
    extern unsigned long hwtimer_now(void);
    unsigned int time = hwtimer_now();
    if (my_active_thread && (pidlist[my_active_thread->pid].laststart)) {
        pidlist[my_active_thread->pid].runtime += time - pidlist[my_active_thread->pid].laststart;
    }
#endif

    DEBUG("\nscheduler: previous task: %s\n", ( my_active_thread == NULL) ? "none" : my_active_thread->name );

    if (num_tasks == 0) {
        DEBUG("scheduler: no tasks left.\n");
        while(! num_tasks);
        DEBUG("scheduler: new task created.\n");
    }

    my_active_thread = NULL;
    while(! my_active_thread) {

        //        for (int i = 0; i < SCHED_PRIO_LEVELS; i++) { /* TODO: introduce bitfield cache */
        //            if (runqueues[i]) {
        int nextrq = number_of_lowest_bit(runqueue_bitcache);
        clist_node_t next = *(runqueues[nextrq]);
        DEBUG("scheduler: first in queue: %s\n", ((tcb*)next.data)->name);
        clist_advance(&(runqueues[nextrq]));
        my_active_thread = (tcb*)next.data;
        thread_pid = (volatile int) my_active_thread->pid;
#if SCHEDSTATISTICS
        pidlist[my_active_thread->pid].laststart = time;
        pidlist[my_active_thread->pid].schedules ++;
#endif
        //                break;
        //            }
        //        }
    }

    DEBUG("scheduler: next task: %s\n", my_active_thread->name);

    if (my_active_thread != active_thread) {
        if (active_thread != NULL) { //TODO: necessary?
            if (active_thread->status ==  STATUS_RUNNING) {
                active_thread->status =  STATUS_PENDING ;
            }
        }
        sched_set_status((tcb*)my_active_thread,  STATUS_RUNNING);
    }

    active_thread = (volatile tcb*) my_active_thread;

    DEBUG("scheduler: done.\n");
}


void sched_set_status(tcb *process, unsigned int status) {
    if (status &  STATUS_ON_RUNQUEUE) {
        if (! (process->status &  STATUS_ON_RUNQUEUE)) {
            DEBUG("adding process %s to runqueue %u.\n", process->name, process->priority);
            clist_add(&runqueues[process->priority], &(process->rq_entry));
            runqueue_bitcache |= 1 << process->priority;
        }
    } else {
        if (process->status & STATUS_ON_RUNQUEUE) {
            DEBUG("removing process %s from runqueue %u.\n", process->name, process->priority);
            clist_remove(&runqueues[process->priority], &(process->rq_entry));
            if (! runqueues[process->priority] ) {
                runqueue_bitcache &= ~(1 << process->priority);
            }
        }
    }
    process->status = status;
}

extern void cpu_switch_context_exit(void);

void sched_task_exit(void) {
    DEBUG("sched_task_exit(): ending task %s...\n", active_thread->name);

    tcb* thread = (tcb*)active_thread;
    dINT();
    sched_threads[active_thread->pid] = NULL;
    num_tasks--;
    
    sched_set_status((tcb*)active_thread,  STATUS_STOPPED);

    free(((tcb*)active_thread)->stack_start);
    active_thread = NULL;
    cpu_switch_context_exit();
}
