#ifndef PRINT_H
#define PRINT_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lexer/lexer.h"
#include "structs.h"

char *print_function(maillon *lex, context_var *context);

#endif // PRINT_H
