#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int fn(int z, int r)
{
    printf("%d", z);
    return r;
}

int main()
{
    int x = 0; // boo
    int y = 3 + x;
    y = fn(x, y);
    // x = y + 1;
    y = 85 + x + x / y;
    x = x * y * 2;
    bool while_a = true;
    while_a = false && while_a;
    printf("%d %d\n", (3 * x + y - 4), y);
    return y;
}