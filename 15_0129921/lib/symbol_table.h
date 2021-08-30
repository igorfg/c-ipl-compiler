#ifndef SYMBOL_TABLE_H_INCLUDED
#define SYMBOL_TABLE_H_INCLUDED

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utlist.h"
#include "utstack.h"

typedef struct symbol_table_entry symbol_table_entry_t;
typedef struct inner_scope inner_scope_t;
typedef struct symbol_table symbol_table_t;
typedef struct scope_stack_element scope_stack_element_t;

struct symbol_table_entry {
  char* id;
  char* data_type;
  union {
    int32_t int_type;
    float float_type;
  };
  symbol_table_entry_t* prev;
  symbol_table_entry_t* next;
};

struct symbol_table {
  char* scope_id;
  symbol_table_t* parent;
  symbol_table_entry_t* entries;
  inner_scope_t* inner_scopes;
};

struct inner_scope {
  symbol_table_t* symbol_table;
  inner_scope_t* prev;
  inner_scope_t* next;
};

struct scope_stack_element {
  char* scope_id;
  scope_stack_element_t* next;
};

symbol_table_t* initialize_symbol_table(char*);
void add_symbol_table_entry(symbol_table_t*, char*, char*);
void add_symbol_table_to_inner_scope(symbol_table_t*, symbol_table_t*);
void print_symbol_table(symbol_table_t*, int);
scope_stack_element_t* add_element_to_stack(scope_stack_element_t*, char*);

// Initialize symbol table
symbol_table_t *symbol_table;
symbol_table_t *current_symbol_table;

#endif
