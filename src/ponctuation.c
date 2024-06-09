#include "ponctuation.h"

char *ponct(maillon *lex, context_var *context)
{
    if (!strcmp(lex->argument, "}"))
    {
        if (aucune_boucle(context))
        {

            return ";;\n";
        }
        else
        {
            char c = retire_boucle(context);
            switch (c)
            {
            case 'w':
                // fin de la boucle while
                return "done ;\n";
                break;
            case 'f':
                // fin de la boucle for
                return "done ;\n";
                break;

            case 'i':
                // fin de la boucle if
                if (suivant_sans_ponct(lex)->lexeme == 'V')
                {
                    return "end;\n";
                }
                return "end\n";

            case 'e':
                // fin de la boucle else
                if (suivant_sans_ponct(lex)->lexeme == 'V')
                {
                    return "end;\n";
                }
                return "end\n";
            }
        }
    }
    else if (!strcmp(lex->argument, "{"))
    {
        context->for_arg = 0;
        context->args = false;
        context->access_var = false;
        if (context->boucles == NULL)
        {
            return "";
        }
        else
        {
            char c = retire_boucle(context);
            ajoute_boucle(c, context);
            switch (c)
            {
            case 'w':
                // début de la boucle while
                return " do\n";
                break;
            case 'f':
                // début de la boucle for
                return " do\n";
                break;

            case 'i':
                // début de la boucle if
                return " then begin\n";

            case 'e':
                // début de la boucle else
                return " begin\n";
            }
        }
    }
    else if (!strcmp(lex->argument, "("))
    {
        context->opened_parentheses += 1;
        if (show_parentheses(context) == true || context->args == true)
        {
            return "(";
        }
        else
        {
            return "";
        }
    }
    else if (!strcmp(lex->argument, ")"))
    {
        if (context->args == true)
        {
            context->opened_parentheses -= 1;
            if (context->function_def == true)
            {
                context->function_def = false;
                return ") =\n";
            }
            else
            {
                return ")";
            }
        }
        if (show_parentheses(context) == true)
        {
            context->opened_parentheses -= 1;
            return ")";
        }
        else
        {
            context->opened_parentheses -= 1;
            return "";
        }
    }
    else if (!strcmp(lex->argument, ";"))
    {
        context->access_var = false;
        context->in_print_function = false;
        context->parentheses_var = 2147483647;

        if (context->for_arg >= 3)
        {
            context->for_arg = 0;
        }
        else if (context->for_arg == 1)
        {
            context->for_arg += 1;
            return " to ";
        }
        else if (context->for_arg > 0)
        {
            context->for_arg += 1;
            return "";
        }
        else if (context->in_var_def == true)
        {
            context->in_var_def = false;
            return ") in \n";
        }

        else if (suivant_sans_ponct(lex)->lexeme == 'V')
        {
            return ";\n";
        }
        return "\n";
    }
    else if (!strcmp(lex->argument, ","))
    {
        if (context->args == true)
        {
            return ",";
        }
    }
    return "";
}
