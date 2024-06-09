#ifndef STRUCTS_H
#define STRUCTS_H
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pile
{
    char valeur;
    struct pile *suivant;
};
typedef struct pile pile;

struct context_var
{
    bool function_def;      // true si on définit une fonction
    bool args;              // true si on est dans les arguments d'une fonction ou d'une boucle
    bool in_var_def;        // true si on est dans la définition d'une variable
    bool access_var;        // true si on a besoin d'acceder aux valeures de d'une variable
    bool in_print_function; // true si on est dans une fonction printf
    int opened_parentheses; // compte le nombre de parenthèses ouvrantes
    int parentheses_var;    // garde le compteur à un certain moment et affiche les parenthèse tant que opened_parenthese est au dessus de ce compteur
    pile *boucles;          // permet de savoir dans quelle boucle on est ('w'->while, 'i'->if, 'e'->else)
};
typedef struct context_var context_var;

void context_init(context_var *context);

bool show_parentheses(context_var *context);

// Structure de pile
pile *init_pile();
bool aucune_boucle(context_var *context);
void ajoute_boucle(char c, context_var *context);
char retire_boucle(context_var *context);

#endif // !STRUCTS_H
