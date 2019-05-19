#include "mdo.h"
#include "stm32f0xx.h"
#include "csw/common/cswtypes.h"

typedef struct
{
  GPIO_TypeDef * GPIOx;
  uint16 GPIO_Pin;
}
mdo_desc_t;

const mdo_desc_t mdo_desc[MDO_CH_MAX] =
{
  { GPIOB, GPIO_Pin_12 },
  { GPIOB, GPIO_Pin_13 },
  { GPIOB, GPIO_Pin_14 },
  { GPIOB, GPIO_Pin_15 },
};

void mdo_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* GPIOB Periph clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

  /* Configure PB12~PB15 as output low */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_ResetBits(GPIOB, GPIO_InitStructure.GPIO_Pin);
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void mdo_setState(mdo_channel_t ch, mdo_command_t cmd)
{
  if( ch<MDO_CH_MAX )
  {
    uint8 i = (uint8)ch;
	GPIO_TypeDef * GPIOx = mdo_desc[i].GPIOx;
	uint16 Pin = mdo_desc[i].GPIO_Pin;
	switch(cmd)
	{
	  case MDO_CMD_LOW:
	    GPIOx->BRR = Pin;
	    break;
	  case MDO_CMD_HIGH:
	    GPIOx->BSRR = Pin;
		break;
	  case MDO_CMD_INV:
	    GPIOx->ODR ^= Pin;
		break;
	  default:
	    break;
	}
  }
}
