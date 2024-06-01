#include "operateur.h"

// Change les opérateurs C vers OCaml
char *operateur(char *ope_c)
{
    if (!strcmp(ope_c, "=="))
    {
        return "=";
    }
    else if (!strcmp(ope_c, "!="))
    {
        return "<>";
    }
    else if (!strcmp(ope_c, "!"))
    {
        return "not";
    }
    else if (!strcmp(ope_c, "%"))
    {
        return "mod";
    }
    else if (!strcmp(ope_c, "="))
    {
        return ":=";
    }
    // Les autres sont inchangés
    else
    {
        return ope_c;
    }
}