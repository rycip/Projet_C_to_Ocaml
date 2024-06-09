#include "util.h"

maillon *suivant_sans_espaces(maillon *lex) // prend le prochain lexème qui n'est pas un espace
{
    lex = lex->suivant;
    while (!strcmp(lex->argument, " "))
    {
        if (lex->suivant == NULL)
        {
            return lex;
        }
        lex = lex->suivant;
    }
    return lex;
}

maillon *suivant_sans_ponct(maillon *lex) // prend le prochain lexème qui n'est pas de la ponctuation
{
    lex = lex->suivant;
    while (lex->lexeme == 'P')
    {
        if (lex->suivant == NULL)
        {
            return lex;
        }
        lex = lex->suivant;
    }
    return lex;
}