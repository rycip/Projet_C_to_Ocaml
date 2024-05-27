#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lexer/lexer.h" //importe les fonctions du fichier lexer.c
#include "structs.h"
#include "ponctuation.h"
#include "variables.h"

FILE *s;
FILE *d;

void traducteur(maillon *lex, FILE *d, context_var *context)
{
    if (lex == NULL)
    {
        exit(0);
    }
    else
    {
        char *out;
        switch (lex->lexeme)
        {
        case 'P':
            // Ponctuation
            out = ponct(lex->argument, context);
            fprintf(d, "%s", out);
            break;
        case 'O':
            // Opérateur
            fprintf(d, "%s", lex->argument);
            break;
        case 'V':
            // Variable
            out = variables(lex->argument, context);
            fprintf(d, "%s", out);
            free(out);
            break;
        case '0':
            // Entier
            fprintf(d, "%s", lex->argument);
            break;
        case 'T':
            context->def_var = true;
            break;
        case 'C':
            // Commentaire
            fprintf(d, "(* %s *)\n", lex->argument);
            break;
        case 'M':
            // Mot clé
            // todo
            break;
        case 'S':
            // Chaine de caractère
            // todo
            break;
        case 'B':
            // Opérateur binaire
            // todo
            break;
        case 'E':
            // Opérateur d'affectation
            // todo
            break;
        case 'D':
            // Début
            break;
        }
        traducteur(lex->suivant, d, context);
    }
}

int main(int argc, char const *argv[])
{
    if (argc <= 2)
    {
        printf("utiliser : ./main <fichier_c> <sortie>\n");
        return 1;
    }
    s = fopen(argv[1], "r");
    d = fopen(argv[2], "w");
    context_var *context = malloc(sizeof(context_var));
    context->in_function = false;
    context->in_var_def = false;
    context->var_dep = false;
    context->def_var = false;
    maillon *lex = lexeur(s);
    traducteur(lex, d, context);
    return 0;
}
