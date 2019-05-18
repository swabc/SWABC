#ifndef __DEMO_0_H
#define __DEMO_0_H

/* initialization of this module, 
 * called by system init after POR */
extern void demo0_init(void);

/* task of this module,
 * called by system scheduler cyclically,
 * handle the most of the functional logics */
extern void demo0_task(void);

/* required output interface,
 * this module turns the LED on/off by calling this interface.
 * argument state: TRUE - the LED will turns on,
 *                 FALSE - the LED will turns off. */
extern void demo0_ro_setLedState(bool state);

#endif // __DEMO_0_H
