#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

char *variables(char *arg, context_var *context)
{
    char *out;
    if (!strcmp(arg, "main"))
    {
        asprintf(&out, "");
        return out;
    }
    if (context->in_var_def == false)
    {
        if (context->var_dep == false)
        {
            asprintf(&out, "let %s = ref ", arg);
        }
        else
        {
            asprintf(&out, "in let %s = ref ", arg);
        }
        context->in_var_def = true;
        return out;
    }
    else
    {
        asprintf(&out, "!%s ", arg);
        return out;
    }
}