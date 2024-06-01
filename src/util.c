#include "util.h"

maillon *suivant_sans_espaces(maillon *lex)
{
    lex = lex->suivant;
    while (!strcmp(lex->argument, " "))
    {
        if (lex->suivant == NULL)
        {
            exit(0);
        }
        lex = lex->suivant;
    }
    return lex;
}