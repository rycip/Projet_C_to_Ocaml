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
#include "operateur.h"
#include "util.h"
#include "mot_cle.h"

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
            out = ponct(lex, context);
            fprintf(d, "%s", out);
            break;
        case 'O':
            // Opérateur
            fprintf(d, "%s", operateur(lex->argument, context));
            break;
        case 'V':
            // Variable
            out = variables(lex, context);
            fprintf(d, "%s", out);
            free(out);
            break;
        case '0':
            // Entier
            if (context->for_arg != 3) // cas spécal de la 3e partie des arguments de la boucle for en c qui ne servent pas ocaml
            {
                fprintf(d, "%s", lex->argument);
            }
            break;
        case 'T':
            // Types
            lex = suivant_sans_espaces(lex);
            fprintf(d, "%s", definition_variable(lex, context));
            break;
        case 'C':
            // Commentaire
            fprintf(d, "(* %s *)\n", lex->argument);
            break;
        case 'M':
            // Mot clé
            fprintf(d, "%s ", mot_cle(lex, context));
            break;
        case 'S':
            // Chaine de caractère
            fprintf(d, " %s ", lex->argument);
            // todo
            break;
        case 'B':
            // Opérateurs binaires
            fprintf(d, "%s", operateur(lex->argument, context));
            break;
        case 'E':
            // Opérateur d'affectation
            if (context->in_var_def == false)
            {
                fprintf(d, "%s", operateur(lex->argument, context));
            }
            break;
        case 'b':
            // booleen
            fprintf(d, "%s", lex->argument);
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
    s = fopen(argv[1], "r"); // fichier c d'entrée
    d = fopen(argv[2], "w"); // fichier ocaml de sortie
    context_var *context = malloc(sizeof(context_var));
    context_init(context);
    maillon *lex = lexeur(s);
    traducteur(lex, d, context);
    free(context);
    return 0;
}
