#include "csw/framework/bisch/bisch.h"
#include "inc/api.h"
#include "../msp/mcu.h"
#include "../msp/mdo.h"

void bisch_r_init(void)
{
  /* basic */
  mcu_init();
  mdo_init();
  mcu_initTick();

  /* csw */

  /* bsw */

  /* asw */
  bsw_r_init();
}

void bisch_r_taskIdle(void)
{
  bsw_r_taskIdle();
}

void bisch_r_taskX1(void)
{
  bsw_r_taskX1();
}

void bisch_r_taskX2(void)
{
  bsw_r_taskX2();
}

void bisch_r_taskX4(void)
{
  bsw_r_taskX4();
}

void bisch_r_taskX8(void)
{
  bsw_r_taskX8();
}

void bisch_r_taskX16(void)
{
  bsw_r_taskX16();
}

void bisch_r_taskX32(void)
{
  bsw_r_taskX32();
}

void bisch_r_taskX64(void)
{
  bsw_r_taskX64();
}

void bisch_r_taskX128(void)
{
  bsw_r_taskX128();
}

void bisch_r_taskX256(void)
{
  bsw_r_taskX256();
}
