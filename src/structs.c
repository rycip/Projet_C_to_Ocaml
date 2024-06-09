#include "structs.h"

pile *init_boucle()
{
    pile *p = malloc(sizeof(pile));
    p->valeur = 'd'; // 'd' pour départ
    p->suivant = NULL;
    return p;
}

void context_init(context_var *context)
{
    context->function_def = false;
    context->args = false;
    context->in_var_def = false;
    context->access_var = false;
    context->in_print_function = false;
    context->opened_parentheses = 0;
    context->parentheses_var = 2147483647;
    context->boucles = init_boucle();
}

bool show_parentheses(context_var *context)
{
    return context->opened_parentheses > context->parentheses_var;
}

bool aucune_boucle(context_var *context)
{
    return context->boucles->valeur == 'd';
}

void ajoute_boucle(char c, context_var *context)
{
    pile *p2 = malloc(sizeof(pile));
    p2->valeur = c;
    p2->suivant = context->boucles;
    context->boucles = p2;
}

char retire_boucle(context_var *context)
{
    assert(context->boucles != NULL);
    pile *p2 = context->boucles;
    char c = p2->valeur;
    context->boucles = p2->suivant;
    free(p2);
    return c;
}
