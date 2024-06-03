#include "print.h"

char *print_function(maillon *lex, context_var *context)
{
    context->in_print_function = true;
    context->access_var = true;
    context->parentheses_var = context->opened_parentheses + 1;
    return "Printf.printf";
}