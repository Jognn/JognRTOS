#include "systick.h"


extern int main(void);

void init(void)
{
    systick_init(1000);

    

    // 4) Call main
    main();
}