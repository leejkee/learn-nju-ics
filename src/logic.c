#include <stdio.h>
#include <unistd.h>

#define FOR_REGS(_) _(X) _(Y) _(Z)
#define LOGIC                    \
    Z1 = !Z;                     \
    Y1 = (!Y && Z) || (!Z && Y); \
    X1 = (X && (!(Y && Z))) || ((Y && Z) && (!X));

#define LOGIC_OTHER                  \
    X1 = !((X && Y) || (!(Y || X))); \
    Y1 = !Y;
#define DEFINE(X) static int X, X##1;
#define UPDTAE(X) X = X##1;
#define PRINT(X) printf(#X " = %d;", X);

void init_logic(void)
{
    FOR_REGS(DEFINE);
    while (1)
    {
        FOR_REGS(PRINT);
        putchar('\n');
        sleep(1);
        LOGIC;
        FOR_REGS(UPDTAE);
    }
}
