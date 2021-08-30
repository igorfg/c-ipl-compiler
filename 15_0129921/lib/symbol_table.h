#ifndef SYMBOL_TABLE_H_INCLUDED
#define SYMBOL_TABLE_H_INCLUDED

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utlist.h"
#include "utstack.h"

typedef struct symbol_table_entry symbol_table_entry_t;
typedef struct inner_scopes inner_scopes_t;
typedef struct symbol_table symbol_table_t;
typedef struct scope_stack scope_stack_t;

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
  inner_scopes_t* inner_scopes;
};

struct inner_scopes {
  symbol_table_t* symbol_table;
  inner_scopes_t* prev;
  inner_scopes_t* next;
};

struct scope_stack {
  char* scope_id;
  scope_stack_t* next;
};

symbol_table_t* initialize_symbol_table(char* scope_id);
void add_symbol_table_entry(symbol_table_t*, char*, char*);
void print_symbol_table(symbol_table_t*, int);

// Initialize symbol table
symbol_table_t *symbol_table;
symbol_table_t *current_symbol_table;

#endif
