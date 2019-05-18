#include "inc/api.h"
#include "asw/demo/demo0.h"
#include "asw/demo/demo1.h"

void bsw_r_init(void)
{
  demo0_init();
}

void bsw_r_taskIdle(void)
{
}

void bsw_r_taskX1(void)
{
}

void bsw_r_taskX2(void)
{
}

void bsw_r_taskX4(void)
{
}

void bsw_r_taskX8(void)
{
}

void bsw_r_taskX16(void)
{
}

void bsw_r_taskX32(void)
{
}

void bsw_r_taskX64(void)
{
}

void bsw_r_taskX128(void)
{
}

void bsw_r_taskX256(void)
{
  demo0_task();
}
