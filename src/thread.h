#ifndef JOGNRTOS_THREAD_H
#define JOGNRTOS_THREAD_H

#include "stdint.h"


#define INVALID_THREAD_ID (0)

typedef uint8_t ThreadId;

typedef void (* ThreadTask)(void);

enum ThreadState
{
    WAITING,
    RUNNING
};


void thread_create(uint8_t* stack, unsigned stackSize, uint8_t priority, ThreadTask threadTask);

void thread_sleep(unsigned milliseconds);


#endif //JOGNRTOS_THREAD_H
