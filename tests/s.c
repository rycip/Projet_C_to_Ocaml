#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int x = 0; // boo
    int y = 3 + x;
    // x = y + 1;
    y = 85 + x +x / y;
    x = x*y*2;
    bool while_a = true;
    while_a = false && while_a;
    printf("%d %d\n", (3 * x + y - 4), y);
    int i = 0;
    while (i == 0){
        i = i + 1;
    }
}