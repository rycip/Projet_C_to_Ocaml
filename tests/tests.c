#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lexer/lexer.h" //importe les fonctions du fichier lexer.c

int main(int argc, char const *argv[])
{
    if (argc <= 1)
    {
        return 1;
    }
    FILE *s = fopen(argv[1], "r");
    affiche_liste(lexeur(s));
    return 0;
}