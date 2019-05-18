#include "demo0.h"
#include "csw/common/cswtypes.h"

typedef struct
{
  bool state:1;
}
demo0_t;

demo0_t demo0;

/* initialization of this module, 
 * called by system init after POR */
void demo0_init(void)
{
  demo0.state = 0;
  demo0_ro_setLedState(demo0.state);
}

/* task of this module,
 * called by system scheduler cyclically,
 * handle the most of the functional logics */
void demo0_task(void)
{
  demo0.state = ~demo0.state;
  demo0_ro_setLedState(demo0.state);
}
