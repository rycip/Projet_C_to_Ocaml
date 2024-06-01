#include "ponctuation.h"

char *ponct(maillon *lex, context_var *context)
{
    if (!strcmp(lex->argument, "}"))
    {
        context->in_function = false;
        return ";;";
    }
    if (!strcmp(lex->argument, "{"))
    {
        context->in_function = true;
        return "";
    }
    if (!strcmp(lex->argument, ";"))
    {
        if (context->in_var_def == true)
        {
            context->in_var_def = false;
            return ") in \n";
        }
        return "\n";
    }
    return "";
}
