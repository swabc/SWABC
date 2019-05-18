#ifndef __DEMO_1_H
#define __DEMO_1_H

#include "csw/common/cswtypes.h"

/* initialization of this module, 
 * called by system init after POR */
extern void demo1_init(void);

/* task of this module,
 * called by system scheduler cyclically,
 * handle the most of the functional logics */
extern void demo1_task(void);

/* required input interface,
 * this module gets the button state by calling this interface.
 * return value: TRUE - the button is pressed
 *               FALSE - the button is not pressed or unknown */
extern bool demo1_ri_getButtonState(void);

/* required output interface,
 * this module turns the LED on/off by calling this interface.
 * argument state: TRUE - the LED will turns on,
 *                 FALSE - the LED will turns off. */
extern void demo1_ro_setLedState(bool state);

#endif // __DEMO_1_H
