#include "mot_cle.h"

char *mot_cle(maillon *lex, context_var *context)
{
    if (!strcmp(lex->argument, "while"))
    {
        ajoute_boucle('w', context);
        context->args = true;
        context->access_var = true;
    }
    if (!strcmp(lex->argument, "if"))
    {
        char c = retire_boucle(context);
        if (c == 'e')
        {
            ajoute_boucle('i', context);
        }
        else
        {
            ajoute_boucle(c, context);
            ajoute_boucle('i', context);
        }
        context->args = true;
        context->access_var = true;
    }
    if (!strcmp(lex->argument, "else"))
    {
        ajoute_boucle('e', context);
        context->args = true;
        context->access_var = true;
    }
    return lex->argument;
}