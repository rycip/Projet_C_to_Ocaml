#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main(void)
{
    FILE *s = fopen("./s", "r");
    affiche_liste(lexeur(s));
}