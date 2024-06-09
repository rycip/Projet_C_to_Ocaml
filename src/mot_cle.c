#include "mot_cle.h"


char* mot_cle(maillon* lex,context_var* context){

    context->access_var = true;
    context->accolades_var = context->accolades_ouvrantes + 1;
    context->parentheses_var = context->parentheses_var + 1 ;
    if (!strcmp(lex->argument,"while")){
        context->boucle = true;
    }
    return lex->argument;
}