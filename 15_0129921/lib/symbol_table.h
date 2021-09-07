#ifndef SYMBOL_TABLE_H_INCLUDED
#define SYMBOL_TABLE_H_INCLUDED

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utlist.h"

typedef struct symbol_table_entry symbol_table_entry_t;
typedef struct inner_scope inner_scope_t;
typedef struct symbol_table symbol_table_t;
typedef struct func_param func_param_t;

struct symbol_table_entry {
  char* id;
  char* data_type;
  int is_function;
  union {
    int32_t int_type;
    float float_type;
  };
  symbol_table_entry_t* prev;
  symbol_table_entry_t* next;
};

struct func_param {
  char* id;
  char* data_type;
  func_param_t* prev;
  func_param_t* next;
};

struct symbol_table {
  int scope_id;
  symbol_table_t* parent;
  symbol_table_entry_t* entries;
  inner_scope_t* inner_scopes;
};

struct inner_scope {
  symbol_table_t* symbol_table;
  inner_scope_t* prev;
  inner_scope_t* next;
};

symbol_table_t* initialize_symbol_table(int);
void add_symbol_table_entry(symbol_table_t*, char*, char*, int);
void add_symbol_table_to_inner_scope(symbol_table_t*, symbol_table_t*);
void print_symbol_table(symbol_table_t*, int);
void free_symbol_table(symbol_table_t*);
void save_func_param(char*, char*);
void add_params_to_symbol_table(symbol_table_t*);

// Initialize symbol table
symbol_table_t* symbol_table;
symbol_table_t* current_symbol_table;
func_param_t* func_params_list;

#endif
