#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void context_init(context_var *context)
{
    context->in_function = false;
    context->in_var_def = false;
    context->access_var = false;
    context->in_print_function = false;
    context->opened_parentheses = 0;
    context->parentheses_var = 2147483647;
    context->accolades_ouvrantes = 0;
    context->accolades_var = 2147483647;
    context->boucle = false;
}

bool show_parentheses(context_var *context)
{
    return context->opened_parentheses > context->parentheses_var;
}

bool show_accolades(context_var *context)
{
    return context->accolades_ouvrantes > context->accolades_var;
}