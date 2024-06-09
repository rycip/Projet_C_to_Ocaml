#ifndef UTIL_H
#define UTIL_H
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lexer/lexer.h"

maillon *suivant_sans_espaces(maillon *lex); // prend le prochain lexème qui n'est pas un espace
maillon *suivant_sans_ponct(maillon *lex);   // prend le prochain lexème qui n'est pas de la ponctuation

#endif // !UTIL_H
