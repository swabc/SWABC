/* bisch is short for Binary Scheduler.
 * this is a task scheduler based on a binary algorithm */

#include "bisch.h"
#include "csw/common/cswtypes.h"

typedef struct
{
  struct
  {
    uint8 tick; // tick from external input
  }
  input;
  struct
  {
    uint8 tick; // tick follow up to the external input
    uint8 cycle;  // schedule counter
  }
  local;
}
bisch_t;

bisch_t bisch;

/* inialization of this module,
 * should be called after system initializatioin after POR.
 */
void bisch_init(void)
{
  bisch.input.tick = 0;
  bisch.local.tick = 0;
  bisch.local.cycle = 0;

  bisch_r_init();
}

/* task scheduler main function,
 * should be called after bisch_init(),
 * NOTE: this function never returns.
 */
void bisch_main(void)
{
  for(;;)
  {
    /* check if tick is updated */
    if( bisch.local.tick == bisch.input.tick )
    {
      /* not updated, run idle */
      bisch_r_taskIdle();
    }
    else
    {
      /* updated */
      bisch.local.tick = bisch.input.tick;

      /* cycle up */
      bisch.local.cycle++;

      /* schedule tasks */
      bisch_r_taskX1();
      if( bisch.local.cycle & 0x01 ) bisch_r_taskX2();
      else if( bisch.local.cycle & 0x02 ) bisch_r_taskX4();
      else if( bisch.local.cycle & 0x04 ) bisch_r_taskX8();
      else if( bisch.local.cycle & 0x08 ) bisch_r_taskX16();
      else if( bisch.local.cycle & 0x10 ) bisch_r_taskX32();
      else if( bisch.local.cycle & 0x20 ) bisch_r_taskX64();
      else if( bisch.local.cycle & 0x40 ) bisch_r_taskX128();
      else if( bisch.local.cycle & 0x80 ) bisch_r_taskX256();
      else ; /* reserve for cpu load calculation */
    }
  }
}

/* tick up event input, 
 * this event should be raised cyclically,
 * then this function is called,
 * the cycle is the time slice of the task scheduler.
 * it can be called from interrupt subroutine.
 * usually the cycle could be less than 10ms.
 */
void bisch_tickUpIsr(void)
{
  bisch.input.tick++;
}


