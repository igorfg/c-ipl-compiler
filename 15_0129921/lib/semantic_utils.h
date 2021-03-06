#ifndef SEMANTIC_UTILS_H_INCLUDED
#define SEMANTIC_UTILS_H_INCLUDED
#include "syn.tab.h"
#include "symbol_table.h"
#include "syntax_tree.h"

int count_number_of_arguments(node_t*);
int check_entry_in_symbol_table(symbol_table_t*, node_t*);
int check_redeclared_id(symbol_table_t*, node_t*);
int check_redeclared_param(node_t*);
int check_number_of_arguments(node_t*, node_t*);
int check_unary_operation_type(node_t*);
int check_binary_operation_type(node_t*);
int check_param_types(node_t*, node_t*);
int check_return_type(node_t*, node_t*);
int check_read_type(node_t*);
int check_write_type(node_t*);


extern char* INT_TYPE_STR;
extern char* FLOAT_TYPE_STR;
extern char* LIST_TYPE_STR;
extern char* INT_LIST_TYPE_STR;
extern char* FLOAT_LIST_TYPE_STR;
extern char* INT_TO_FLOAT_STR;
extern char* FLOAT_TO_INT_STR;
extern char* STRING_LITERAL;
extern int current_line;
extern int previous_col;

#endif