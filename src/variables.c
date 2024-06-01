#include "variables.h"

char *variables(maillon *lex, context_var *context)
{
    char *out;
    if (context->in_var_def == true)
    {
        asprintf(&out, "!%s", lex->argument);
        return out;
    }
    else
    {
        asprintf(&out, "%s", lex->argument);
        context->in_var_def = false;
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
    else
    {
        asprintf(&out, "let %s = ref (", lex->argument);
        context->in_var_def = true;
        return out;
    }
}