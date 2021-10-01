#ifndef SEMANTIC_UTILS_H_INCLUDED
#define SEMANTIC_UTILS_H_INCLUDED
#include "symbol_table.h"
#include "syn.tab.h"

int find_entry_in_symbol_table(symbol_table_t*, char*);
int check_redeclared_id(symbol_table_t*, char*);
int check_redeclared_param(char*);

#endif