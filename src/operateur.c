#include "operateur.h"

// Change les opérateurs C vers OCaml
char *operateur(char *ope_c, context_var *context)
{
    if (context->for_arg == 2 || context->for_arg == 3)
    {
        return "";
    }
    else if (context->for_arg == 1)
    {
        return ope_c;
    }
    else if (!strcmp(ope_c, "=="))
    {
        return " = ";
    }
    else if (!strcmp(ope_c, "!="))
    {
        return " <> ";
    }
    else if (!strcmp(ope_c, "!"))
    {
        return " not ";
    }
    else if (!strcmp(ope_c, "%"))
    {
        return " mod ";
    }
    else if (!strcmp(ope_c, "="))
    {
        return " := ";
    }
    // Les autres sont inchangés
    else
    {
        return ope_c;
    }
}