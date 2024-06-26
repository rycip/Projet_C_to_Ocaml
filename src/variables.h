#ifndef VARIABLES_H
#define VARIABLES_H
#define _GNU_SOURCE

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "../lexer/lexer.h"
#include "print.h"

char *variables(maillon *lex, context_var *context);
char *definition_variable(maillon *lex, context_var *context);
#endif // !VARIABLES_H