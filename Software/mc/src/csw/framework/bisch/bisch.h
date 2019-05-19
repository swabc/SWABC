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
 * usually the cycle could be less than 10ms.
 */
extern void bisch_tickUpIsr(void);

/* task init, will be called in bisch init to init all the tasks. */
extern void bisch_r_init(void);

/* idle task, will be called if the time slice is not end. */
extern void bisch_r_taskIdle(void);

/* X1 task, will be scheduled every time after the tick update. */
extern void bisch_r_taskX1(void);

/* X2 task, will be scheduled every 2 times of the tick update. */
extern void bisch_r_taskX2(void);

/* X4 task, will be scheduled every 4 times of the tick update. */
extern void bisch_r_taskX4(void);

/* X8 task, will be scheduled every 8 times of the tick update. */
extern void bisch_r_taskX8(void);

/* X16 task, will be scheduled every 16 times of the tick update. */
extern void bisch_r_taskX16(void);

/* X32 task, will be scheduled every 32 times of the tick update. */
extern void bisch_r_taskX32(void);

/* X64 task, will be scheduled every 64 times of the tick update. */
extern void bisch_r_taskX64(void);

/* X128 task, will be scheduled every 128 times of the tick update. */
extern void bisch_r_taskX128(void);

/* X256 task, will be scheduled every 256 times of the tick update. */
extern void bisch_r_taskX256(void);

#endif // __BISCH_H


