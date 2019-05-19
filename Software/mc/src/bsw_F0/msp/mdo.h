#ifndef  __MDO_H
#define  __MDO_H

typedef enum
{
  MDO_CH_PB12,
  MDO_CH_PB13,
  MDO_CH_PB14,
  MDO_CH_PB15,

  MDO_CH_MAX,
}
mdo_channel_t;

typedef enum
{
  MDO_CMD_LOW,
  MDO_CMD_HIGH,
  MDO_CMD_INV,

  MDO_CMD_MAX,
}
mdo_command_t;

extern void mdo_init(void);

extern void mdo_setState(mdo_channel_t ch, mdo_command_t cmd);

#endif // __MIO_H
