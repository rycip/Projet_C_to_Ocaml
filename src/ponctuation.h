#ifndef PONCTUATION_H
#define PONCTUATION_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "../lexer/lexer.h"
#include "util.h"

char *ponct(maillon *lex, context_var *context);
#endif // !PONCTUATION_H