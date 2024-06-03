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
        context->in_function = true;
        return "";
    }
    else if (!strcmp(lex->argument, ";"))
    {
        context->access_var = false;
        context->in_print_function = false;
        context->parentheses_var = 2147483647;

        if (context->in_var_def == true)
        {
            context->in_var_def = false;
            return " ) in \n";
        }
        return "\n";
    }
    return "";
}
