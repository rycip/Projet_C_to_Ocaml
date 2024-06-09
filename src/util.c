#include "util.h"

maillon *suivant_sans_espaces(maillon *lex) // prend le prochain lexème qui n'est pas un espace
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