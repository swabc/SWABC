#ifndef  __TIMER_H
#define  __TIMER_H

typedef void (*timeOutCallback_t)(void);

typedef struct
{
    uint8   active:1;
    uint16  counter;
    uint16  cycle;
    timeOutCallback_t  timeOutCallback;
}
timer_t;

extern void timer_init(timer_t * t, uint16 cycle, timeOutCallback_t tocb);
extern void timer_task(timer_t * t);

extern void timer_start(timer_t * t);
extern void timer_stop(timer_t * t);
extern uint8 timer_isActive(timer_t * t);
extern uint8 timer_isTimeOut(timer_t * t);

#endif // __TIMER_H
