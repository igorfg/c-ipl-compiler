#include "symbol_table.h"

symbol_table_t* initialize_symbol_table(char* scope_id) {
  symbol_table_t *new_symbol_table = NULL;
  new_symbol_table = (symbol_table_t*)malloc(sizeof(symbol_table_t));
  new_symbol_table->scope_id = (char*)malloc(strlen(scope_id)+1);
  strcpy(new_symbol_table->scope_id, scope_id);
  new_symbol_table->parent = NULL;
  new_symbol_table->entries = NULL;
  new_symbol_table->inner_scopes = NULL;
  return new_symbol_table;
}

void add_symbol_table_entry(symbol_table_t* symbol_table, char* id) {
  symbol_table_entry_t *new_symbol_table_entry = NULL;
  new_symbol_table_entry = (symbol_table_entry_t*)malloc(sizeof(symbol_table_entry_t));
  DL_APPEND(symbol_table->entries, new_symbol_table_entry);
}