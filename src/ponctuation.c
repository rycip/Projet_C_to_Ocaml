#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

char *ponct(char *arg, context_var *context)
{
    if (!strcmp(arg, "}"))
    {
        context->in_function = false;
        return ";;";
    }
    if (!strcmp(arg, "{"))
    {
        context->in_function = true;
        return "";
    }
    if (!strcmp(arg, ";"))
    {
        if (context->in_var_def == true)
        {
            context->in_var_def = false;
            context->var_dep = true;
        }
        return "\n";
    }
    return "";
}
