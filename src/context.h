#include <stdbool.h>

struct context_var
{
    bool in_function; // true si on est dans une fonction
    bool in_var_def;  // true si on est dans la définition d'une variable
    bool var_dep;     // true si il y a une variable locale avant
    bool def_var;
};
typedef struct context_var context_var;