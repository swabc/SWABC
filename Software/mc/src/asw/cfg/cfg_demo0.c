#include "asw/demo/demo0.h"
#include "msp/mdo.h"

/* required output interface,
 * this module turns the LED on/off by calling this interface.
 * argument state: TRUE - the LED will turns on,
 *                 FALSE - the LED will turns off. */
void demo0_ro_setLedState(bool state)
{
  mdo_setState(MDO_CH_PB12,state?MDO_CMD_HIGH:MDO_CMD_LOW);
}

