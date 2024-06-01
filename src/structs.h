#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdbool.h>

struct context_var
{
    bool in_function; // true si on est dans une fonction, main n'est pas compté comme une fonction en ocaml
    bool in_var_def;  // true si on est dans la définition d'une variable
};
typedef struct context_var context_var;

void context_init(context_var *context);
#endif // !STRUCTS_H
