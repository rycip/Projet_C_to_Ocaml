#include "variables.h"

char *variables(maillon *lex, context_var *context)
{
    char *out;
    if (context->access_var == true && context->args == false)
    {
        if (!strcmp(lex->suivant->argument, "(")) // cas d'une utilisation de fonction
        {
            context->args = true;
            asprintf(&out, " %s", lex->argument);
        }
        else
        {
            asprintf(&out, " !%s", lex->argument);
        }
        return out;
    }
    else if (!strcmp(lex->argument, "printf"))
    {
        asprintf(&out, "%s", print_function(lex, context));
        return out;
    }
    else
    {
        if (!strcmp(lex->argument, "return"))
        {
            asprintf(&out, "");
        }
        else if (context->access_var == false)
        {
            asprintf(&out, "%s", lex->argument);
        }
        else
        {
            asprintf(&out, "!%s", lex->argument);
        }
        context->access_var = true;
        context->parentheses_var = context->opened_parentheses;
        return out;
    }
}

char *definition_variable(maillon *lex, context_var *context)
{
    char *out;
    if (!strcmp(lex->argument, "main"))
    {
        asprintf(&out, "");
        return out;
    }
    if (context->args == true)
    {
        asprintf(&out, "%s", lex->argument);
        return out;
    }
    if (!strcmp(lex->suivant->argument, "(")) // cas d'une définition de fonction
    {
        context->function_def = true;
        context->args = true;
        asprintf(&out, "let %s", lex->argument);
        return out;
    }
    else
    {
        asprintf(&out, "let %s = ref (", lex->argument);
        context->in_var_def = true;
        context->access_var = true;
        context->parentheses_var = context->opened_parentheses;
        return out;
    }
}