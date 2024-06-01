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
}