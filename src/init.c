#include "systick.h"


extern int main(void);

extern void thread_init();

void init(void)
{
    systick_init(1000);
    thread_init();

    // 4) Call main
    main();

    while (1);
}