#ifndef AT86AT86RF231_SETTINGS_H
#define AT86AT86RF231_SETTINGS_H

#define AT86RF231_RX_BUF_SIZE   3

enum at86rf231_access
{
    AT86RF231_ACCESS_REG = 0x80,
    AT86RF231_ACCESS_FRAMEBUFFER = 0x20,
    AT86RF231_ACCESS_SRAM = 0x00,

    AT86RF231_ACCESS_READ = 0x00,
    AT86RF231_ACCESS_WRITE = 0x40,
};

enum at86rf231_register
{
    AT86RF231_REG__TRX_STATUS = 0x01,
    AT86RF231_REG__TRX_STATE = 0x02,
    AT86RF231_REG__TRX_CTRL_0 = 0x03,
    AT86RF231_REG__TRX_CTRL_1 = 0x04,
    AT86RF231_REG__PHY_TX_PWR = 0x05,
    AT86RF231_REG__PHY_RSSI = 0x06,
    AT86RF231_REG__PHY_ED_LEVEL = 0x07,
    AT86RF231_REG__PHY_CC_CCA = 0x08,
    AT86RF231_REG__CCA_THRES = 0x09,
    AT86RF231_REG__RX_CTRL = 0x0A,
    AT86RF231_REG__SFD_VALUE = 0x0B,
    AT86RF231_REG__TRX_CTRL_2 = 0x0C,
    AT86RF231_REG__ANT_DIV = 0x0D,
    AT86RF231_REG__IRQ_MASK = 0x0E,
    AT86RF231_REG__IRQ_STATUS = 0x0F,
    AT86RF231_REG__VREG_CTRL = 0x10,
    AT86RF231_REG__BATMON = 0x11,
    AT86RF231_REG__XOSC_CTRL = 0x12,

    AT86RF231_REG__RX_SYN = 0x15,

    AT86RF231_REG__XAH_CTRL_1 = 0x17,
    AT86RF231_REG__FTN_CTRL = 0x18,

    AT86RF231_REG__PLL_CF = 0x1A,
    AT86RF231_REG__PLL_DCU = 0x1B,
    AT86RF231_REG__PART_NUM = 0x1C,
    AT86RF231_REG__VERSION_NUM = 0x1D,
    AT86RF231_REG__MAN_ID_0 = 0x1E,
    AT86RF231_REG__MAN_ID_1 = 0x1F,
    AT86RF231_REG__SHORT_ADDR_0 = 0x20,
    AT86RF231_REG__SHORT_ADDR_1 = 0x21,
    AT86RF231_REG__PAN_ID_0 = 0x22,
    AT86RF231_REG__PAN_ID_1 = 0x23,

    AT86RF231_REG__IEEE_ADDR_0 = 0x24,
    AT86RF231_REG__IEEE_ADDR_1 = 0x25,
    AT86RF231_REG__IEEE_ADDR_2 = 0x26,
    AT86RF231_REG__IEEE_ADDR_3 = 0x27,
    AT86RF231_REG__IEEE_ADDR_4 = 0x28,
    AT86RF231_REG__IEEE_ADDR_5 = 0x29,
    AT86RF231_REG__IEEE_ADDR_6 = 0x2A,
    AT86RF231_REG__IEEE_ADDR_7 = 0x2B,

    AT86RF231_REG__XAH_CTRL_0 = 0x2C,
    AT86RF231_REG__CSMA_SEED_0 = 0x2D,
    AT86RF231_REG__CSMA_SEED_1 = 0x2E,
    AT86RF231_REG__CSMA_BE = 0x2F,


    AT86RF231_REG__TST_CTRL_DIGI = 0x36,
};

enum
{
    AT86RF231_TRX_CTRL_0_MASK__PAD_IO = 0xC0,
    AT86RF231_TRX_CTRL_0_MASK__PAD_IO_CLKM = 0x30,
    AT86RF231_TRX_CTRL_0_MASK__CLKM_SHA_SEL = 0x08,
    AT86RF231_TRX_CTRL_0_MASK__CLKM_CTRL = 0x07,

    AT86RF231_TRX_CTRL_0_DEFAULT__PAD_IO = 0x00,
    AT86RF231_TRX_CTRL_0_DEFAULT__PAD_IO_CLKM = 0x10,
    AT86RF231_TRX_CTRL_0_DEFAULT__CLKM_SHA_SEL = 0x08,
    AT86RF231_TRX_CTRL_0_DEFAULT__CLKM_CTRL = 0x01,

    AT86RF231_TRX_CTRL_0_CLKM_CTRL__OFF = 0x00,
    AT86RF231_TRX_CTRL_0_CLKM_CTRL__1MHz = 0x01,
    AT86RF231_TRX_CTRL_0_CLKM_CTRL__2MHz = 0x02,
    AT86RF231_TRX_CTRL_0_CLKM_CTRL__4MHz = 0x03,
    AT86RF231_TRX_CTRL_0_CLKM_CTRL__8MHz = 0x04,
    AT86RF231_TRX_CTRL_0_CLKM_CTRL__16MHz = 0x05,
    AT86RF231_TRX_CTRL_0_CLKM_CTRL__250kHz = 0x06,
    AT86RF231_TRX_CTRL_0_CLKM_CTRL__62_5kHz = 0x07,
};

enum
{
    AT86RF231_TRX_CTRL_1_MASK__PA_EXT_EN = 0x80,
    AT86RF231_TRX_CTRL_1_MASK__IRQ_2_EXT_EN = 0x40,
    AT86RF231_TRX_CTRL_1_MASK__TX_AUTO_CRC_ON = 0x20,
    AT86RF231_TRX_CTRL_1_MASK__RX_BL_CTRL = 0x10,
    AT86RF231_TRX_CTRL_1_MASK__SPI_CMD_MODE = 0x0C,
    AT86RF231_TRX_CTRL_1_MASK__IRQ_MASK_MODE = 0x02,
    AT86RF231_TRX_CTRL_1_MASK__IRQ_POLARITY = 0x01,
};

enum
{
    AT86RF231_TRX_CTRL_2_MASK__RX_SAFE_MODE = 0x80,
    AT86RF231_TRX_CTRL_2_MASK__OQPSK_DATA_RATE = 0x03,
};

enum
{
    AT86RF231_IRQ_STATUS_MASK__BAT_LOW = 0x80,
    AT86RF231_IRQ_STATUS_MASK__TRX_UR = 0x40,
    AT86RF231_IRQ_STATUS_MASK__AMI = 0x20,
    AT86RF231_IRQ_STATUS_MASK__CCA_ED_DONE = 0x10,
    AT86RF231_IRQ_STATUS_MASK__TRX_END = 0x08,
    AT86RF231_IRQ_STATUS_MASK__RX_START = 0x04,
    AT86RF231_IRQ_STATUS_MASK__PLL_UNLOCK = 0x02,
    AT86RF231_IRQ_STATUS_MASK__PLL_LOCK = 0x01,
};

enum at86rf231_trx_status
{
    AT86RF231_TRX_STATUS_MASK__CCA_DONE = 0x80,
    AT86RF231_TRX_STATUS_MASK__CCA_STATUS = 0x40,
    AT86RF231_TRX_STATUS_MASK__TRX_STATUS = 0x1F,

    AT86RF231_TRX_STATUS__P_ON = 0x00,
    AT86RF231_TRX_STATUS__BUSY_RX = 0x01,
    AT86RF231_TRX_STATUS__BUSY_TX = 0x02,
    AT86RF231_TRX_STATUS__RX_ON = 0x06,
    AT86RF231_TRX_STATUS__TRX_OFF = 0x08,
    AT86RF231_TRX_STATUS__PLL_ON = 0x09,
    AT86RF231_TRX_STATUS__SLEEP = 0x0F,
    AT86RF231_TRX_STATUS__BUSY_RX_AACK = 0x11,
    AT86RF231_TRX_STATUS__BUSY_TX_ARET = 0x12,
    AT86RF231_TRX_STATUS__RX_AACK_ON = 0x16,
    AT86RF231_TRX_STATUS__TX_ARET_ON = 0x19,
    AT86RF231_TRX_STATUS__RX_ON_NOCLK = 0x1C,
    AT86RF231_TRX_STATUS__RX_AACK_ON_NOCLK = 0x1D,
    AT86RF231_TRX_STATUS__BUSY_RX_AACK_NOCLK = 0x1E,
    AT86RF231_TRX_STATUS__STATE_TRANSITION_IN_PROGRESS = 0x1F,
};

enum at86rf231_trx_state
{
    AT86RF231_TRX_STATE__NOP = 0x00,
    AT86RF231_TRX_STATE__TX_START = 0x02,
    AT86RF231_TRX_STATE__FORCE_TRX_OFF = 0x03,
    AT86RF231_TRX_STATE__FORCE_PLL_ON = 0x04,
    AT86RF231_TRX_STATE__RX_ON = 0x06,
    AT86RF231_TRX_STATE__TRX_OFF = 0x08,
    AT86RF231_TRX_STATE__PLL_ON = 0x09,
    AT86RF231_TRX_STATE__RX_AACK_ON = 0x16,
    AT86RF231_TRX_STATE__TX_ARET_ON = 0x19,
};

enum at86rf231_phy_cc_cca
{
    AT86RF231_PHY_CC_CCA_MASK__CCA_REQUEST = 0x80,
    AT86RF231_PHY_CC_CCA_MASK__CCA_MODE = 0x60,
    AT86RF231_PHY_CC_CCA_MASK__CHANNEL = 0x1F,

    AT86RF231_PHY_CC_CCA_DEFAULT__CCA_MODE = 0x20,
};

enum at86rf231_phy_tx_pwr
{
    AT86RF231_PHY_TX_PWR_MASK__PA_BUF_LT = 0xC0,
    AT86RF231_PHY_TX_PWR_MASK__PA_LT = 0x30,
    AT86RF231_PHY_TX_PWR_MASK__TX_PWR = 0x0F,

    AT86RF231_PHY_TX_PWR_DEFAULT__PA_BUF_LT = 0xC0,
    AT86RF231_PHY_TX_PWR_DEFAULT__PA_LT = 0x00,
    AT86RF231_PHY_TX_PWR_DEFAULT__TX_PWR = 0x00,

    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__3dBm = 0x00,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__2_8dBm = 0x01,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__2_3dBm = 0x02,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__1_8dBm = 0x03,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__1_3dBm = 0x04,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__0_7dBm = 0x05,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__0dBm = 0x06,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__m1dBm = 0x07,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__m2dBm = 0x08,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__m3dBm = 0x09,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__m4dBm = 0x0A,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__m5dBm = 0x0B,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__m7dBm = 0x0C,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__m9dBm = 0x0D,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__m12dBm = 0x0E,
    AT86RF231_PHY_TX_PWR_TX_PWR_VALUE__m17dBm = 0x0F,

};

enum at86rf231_phy_rssi
{
    AT86RF231_PHY_RSSI_MASK__RX_CRC_VALID = 0x80,
    AT86RF231_PHY_RSSI_MASK__RND_VALUE = 0x60,
    AT86RF231_PHY_RSSI_MASK__RSSI = 0x1F,
};

enum at86rf231_xosc_ctrl
{
    AT86RF231_XOSC_CTRL__XTAL_MODE_CRYSTAL = 0xF0,
    AT86RF231_XOSC_CTRL__XTAL_MODE_EXTERNAL = 0xF0,
};

enum
{
    AT86RF231_TIMING__VCC_TO_P_ON = 330,
    AT86RF231_TIMING__SLEEP_TO_TRX_OFF = 380,
    AT86RF231_TIMING__TRX_OFF_TO_PLL_ON = 110,
    AT86RF231_TIMING__TRX_OFF_TO_RX_ON = 110,
    AT86RF231_TIMING__PLL_ON_TO_BUSY_TX = 16,

    AT86RF231_TIMING__RESET = 100,
    AT86RF231_TIMING__RESET_TO_TRX_OFF = 37,
};

#endif