#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdbool.h>

struct context_var
{
    bool in_function;       // true si on est dans une fonction, main n'est pas compté comme une fonction en ocaml
    bool in_var_def;        // true si on est dans la définition d'une variable
    bool access_var;        // true si on a besoin d'acceder aux valeures de d'une variable
    bool in_print_function; // true si on est dans une fonction printf
    int opened_parentheses; // compte le nombre de parenthèses ovrantes
    int parentheses_var;    // garde le compteur à un certain moment et affiche les parenthèse tant que opened_parenthese est au dessus de ce compteur
};
typedef struct context_var context_var;

void context_init(context_var *context);

bool show_parentheses(context_var *context);

#endif // !STRUCTS_H
