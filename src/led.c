#include <stdio.h>
#include <unistd.h>

//
#define XOR(X, Y) \
    ((!X && Y) || (!Y && X))

#define FOR_REGS(_) \
    _(W)            \
    _(X)            \
    _(Y) _(Z)

// define the number 0~9
#define ZERO \
    !(W || X || Y || Z)
#define ONE \
    !(W || X || Y || !Z)
#define TWO \
    !(W || X || !Y || Z)
#define THREE \
    !(W || X || !Y || !Z)
#define FOUR \
    !(W || !X || Y || Z)
#define FINE \
    !(W || !X || Y || !Z)
#define SIX \
    !(W || !X || !Y || Z)
#define SEVEN \
    !(W || !X || !Y || !Z)
#define EIGHT \
    !(!W || X || Y || Z)
#define NINE \
    !(!W || X || Y || !Z)

#define OUTPUTS(_) \
    _(A)           \
    _(B)           \
    _(C) _(D) _(E) _(F) _(G)

#define LOGIC                                                                  \
    Z1 = !Z;                                                                   \
    Y1 = XOR(Z, Y) && !NINE;                                                   \
    X1 = ((X && (!(Y && Z))) || ((Y && Z) && (!X))) && !NINE;                  \
    W1 = (W || (X && Y && Z)) && !NINE;                                        \
    A = ZERO || TWO || THREE || FINE || SIX || SEVEN || EIGHT || NINE;         \
    B = ZERO || ONE || TWO || THREE || FOUR || SEVEN || EIGHT || NINE;         \
    C = ZERO || ONE || THREE || FOUR || FINE || SIX || SEVEN || EIGHT || NINE; \
    D = ZERO || TWO || THREE || FINE || SIX || EIGHT || NINE;                  \
    E = ZERO || TWO || SIX || EIGHT;                                           \
    F = ZERO || FOUR || FINE || SIX || EIGHT || NINE;                          \
    G = TWO || THREE || FOUR || FINE || SIX || EIGHT || NINE;

#define DEFINE(X) static int X, X##1;
#define UPDATE(X) X = X##1;
#define PRINT(X) printf(#X " = %d;", X);

void init_led(void)
{
    FOR_REGS(DEFINE);
    OUTPUTS(DEFINE);
    // int count = 20;
    // int num = 0;
    // while (count--)
    while (1)
    {
        // num = W * 8 + X * 4 + Y * 2 + Z * 1;
        // FOR_REGS(PRINT);
        // PRINT(!NINE);
        // PRINT(num);
        LOGIC;
        OUTPUTS(PRINT);
        putchar('\n');
        fflush(stdout);
        sleep(1);
        FOR_REGS(UPDATE);
    }
}
