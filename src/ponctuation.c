#include "ponctuation.h"

char *ponct(maillon *lex, context_var *context)
{
    if (!strcmp(lex->argument, "}"))
    {
        context->in_function = false;
        return ";;";
    }
    else if (!strcmp(lex->argument, "("))
    {
        context->opened_parentheses += 1;
        if (show_parentheses(context) == true)
        {
            return " (";
        }
        else
        {
            return "";
        }
    }
    else if (!strcmp(lex->argument, ")"))
    {
        if (show_parentheses(context) == true)
        {
            context->opened_parentheses -= 1;
            return " )";
        }
        else
        {
            context->opened_parentheses -= 1;
            return "";
        }
    }
    else if (!strcmp(lex->argument, "{"))
    {
        context->accolades_ouvrantes += 1;
        if (show_accolades(context) == true)
        {
            return " (";
        }
        else
        {
            return "";
        }
    }
    else if (!strcmp(lex->argument, "}"))
    {
        if (context->boucle == true)
        {
            context->boucle = false;
            return " done; \n";
        }
        else if (show_accolades(context) == true)
        {
            context->accolades_ouvrantes -= 1;
            return " }";
        }
        else
        {
            context->accolades_ouvrantes -= 1;
            return "";
        }
    }
    else if (!strcmp(lex->argument, ";"))
    {
        context->access_var = false;
        context->in_print_function = false;
        context->parentheses_var = 2147483647;

        // Definition de Variable
        if (context->in_var_def == true)
        {
            context->in_var_def = false;
            return " ) in \n";
        }

        return " ; \n";
    }
    return "";
}
