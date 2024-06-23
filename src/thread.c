#include "thread.h"

#include "arm_cmsis.h"

#include "systick.h"


#define UNUSED(x) ((void)(x))

#define MAX_THREAD_COUNT 5
#define NULL 0

#define GET_PSP_VALUE(stack_base, stack_size) ((uint32_t) ( (uint32_t)&stack_base + stack_size - 1) )


struct ThreadControlBlock
{
    ThreadId id;
    uint8_t priority;
    uint32_t pspValue;
    ThreadTask threadTask;
};

static uint8_t initThreadStack[1024];

static struct ThreadControlBlock tcbPool[MAX_THREAD_COUNT];

static struct ThreadControlBlock* runningThread = NULL;


static int getTcbPoolIndex()
{
    for (int threadIndex = 0; threadIndex < MAX_THREAD_COUNT; ++threadIndex)
    {
        if (tcbPool[threadIndex].id == INVALID_THREAD_ID)
            return threadIndex;
    }

    return -1;
}

static ThreadId getNewThreadId()
{
    static ThreadId threadIdCounter = 1;
    return threadIdCounter++;
}

static void storeRegistersOnStack()
{
    uint32_t* stackPointer = (uint32_t*) runningThread->pspValue;

    // Program Counter
    stackPointer--;
    *stackPointer = (uint32_t) runningThread->threadTask;

    // Link Register
    stackPointer--;
    *stackPointer = 0;

    for (int i = 0; i < 13; ++i)
    {
        stackPointer--;
        stackPointer = 0;
    }

    runningThread->pspValue = (uint32_t) stackPointer;
}

static void schedulerTrySwitch(struct ThreadControlBlock* thread)
{
    if (thread->priority >= runningThread->priority)
    {
        return;
    }

    storeRegistersOnStack();
}

void thread_init()
{
    const uint32_t newPspValue = GET_PSP_VALUE(initThreadStack, sizeof(initThreadStack));

    struct ThreadControlBlock* initThread = &tcbPool[0];
    initThread->id = getNewThreadId();
    initThread->priority = 10;
    initThread->pspValue = newPspValue;
    runningThread = initThread;

    __set_PSP(newPspValue);
    uint32_t controlValue = __get_CONTROL();
    controlValue |= (1 << 1);
    __set_CONTROL(controlValue);
}

void thread_create(uint8_t* stack, unsigned stackSize, uint8_t priority, ThreadTask threadTask)
{
    UNUSED(stackSize);

    const int tcbPoolIndex = getTcbPoolIndex();
    if (tcbPoolIndex < 0)
    {
        return;
    }

    const ThreadId assignedThreadId = getNewThreadId();
    struct ThreadControlBlock* threadControlBlockPtr = &tcbPool[tcbPoolIndex];
    threadControlBlockPtr->id = assignedThreadId;
    threadControlBlockPtr->priority = priority;
    threadControlBlockPtr->pspValue = stack[0];
    threadControlBlockPtr->threadTask = threadTask;

    schedulerTrySwitch(threadControlBlockPtr);
}

void thread_sleep(unsigned milliseconds)
{
    systick_sleep(milliseconds);
}

