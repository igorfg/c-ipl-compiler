#ifndef SEMANTIC_UTILS_H_INCLUDED
#define SEMANTIC_UTILS_H_INCLUDED
#include "syn.tab.h"
#include "symbol_table.h"
#include "syntax_tree.h"

int count_number_of_arguments(node_t*);
int find_entry_in_symbol_table(symbol_table_t*, char*);
int check_redeclared_id(symbol_table_t*, char*);
int check_redeclared_param(char*);
int check_number_of_arguments(symbol_table_t*, char*, node_t*);

#endif