/* bisch is short for Binary Scheduler.
 * this is a task scheduler based on a binary algorithm */

#ifndef  __BISCH_H
#define  __BISCH_H

/* inialization of this module,
 * should be called after system initializatioin after POR.
 */
extern void bisch_init(void);

/* task scheduler main function,
 * should be called after bisch_init(),
 * NOTE: this function never returns.
 */
extern void bisch_main(void);

/* tick up event input, 
 * this event should be raised cyclically,
 * then this function is called,
 * the cycle is the time slice of the task scheduler.
 * it can be called from interrupt subroutine.
 */
extern void bisch_tickUpIsr(void);

#endif // __BISCH_H

