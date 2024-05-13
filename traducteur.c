#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h" //importe les fonctions du fichier lexer.c

struct context_var
{
    bool in_function; // true si on est dans une fonction
    bool in_var_def;  // true si on est dans la définition d'une variable
    bool var_dep;     // true si il y a une variable locale avant
};
typedef struct context_var context_var;

FILE *s;
FILE *d;

char *ponct(char *arg, context_var *context)
{
    if (!strcmp(arg, "}"))
    {
        context->in_function = false;
        return ";;";
    }
    if (!strcmp(arg, "{"))
    {
        context->in_function = true;
        return "";
    }
    if (!strcmp(arg, ";"))
    {
        if (context->in_var_def == true)
        {
            context->in_var_def = false;
            context->var_dep = true;
        }
        return "\n";
    }
    return "";
}

char *variables(char *arg, context_var *context)
{
    char *out;
    if (!strcmp(arg, "main"))
    {
        asprintf(&out, "");
        return out;
    }
    if (context->in_var_def == false)
    {
        if (context->var_dep == false)
        {
            asprintf(&out, "let %s = ref ", arg);
        }
        else
        {
            asprintf(&out, "in let %s = ref ", arg);
        }
        context->in_var_def = true;
        return out;
    }
    else
    {
        asprintf(&out, "!%s ", arg);
        return out;
    }
}

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
            out = ponct(lex->argument, context);
            fprintf(d, "%s", out);
            break;
        case 'O':
            fprintf(d, "%s", lex->argument);
            break;
        case 'V':
            out = variables(lex->argument, context);
            fprintf(d, "%s", out);
            free(out);
            break;
        case '0':
            fprintf(d, "%s", lex->argument);
            break;
        }
        traducteur(lex->suivant, d, context);
    }
}

int main()
{
    s = fopen("./s", "r");
    d = fopen("./d", "w");
    context_var *context = malloc(sizeof(context_var));
    context->in_function = false;
    context->in_var_def = false;
    context->var_dep = false;
    maillon *lex = lexeur(s);
    traducteur(lex, d, context);
}
