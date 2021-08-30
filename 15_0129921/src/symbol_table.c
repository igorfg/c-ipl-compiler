#include "symbol_table.h"

symbol_table_t* initialize_symbol_table(char* id) {
  symbol_table_t *new_symbol_table = NULL;
  new_symbol_table = (symbol_table_t*)malloc(sizeof(symbol_table_t));
  new_symbol_table->scope_id = strdup(id);
  new_symbol_table->parent = NULL;
  new_symbol_table->entries = NULL;
  new_symbol_table->inner_scopes = NULL;
  return new_symbol_table;
}

void add_symbol_table_entry(symbol_table_t* symbol_table, char* id, char* data_type) {
  symbol_table_entry_t *new_symbol_table_entry = NULL;
  new_symbol_table_entry = (symbol_table_entry_t*)malloc(sizeof(symbol_table_entry_t));
  new_symbol_table_entry->id = strdup(id);
  new_symbol_table_entry->data_type = strdup(data_type);
  DL_APPEND(symbol_table->entries, new_symbol_table_entry);
}

void add_symbol_table_to_inner_scope(symbol_table_t* parent, symbol_table_t* child) {
  child->parent = parent;
  inner_scope_t* inner_scope = (inner_scope_t*)malloc(sizeof(inner_scope));
  inner_scope->symbol_table = child;
  DL_APPEND(parent->inner_scopes, inner_scope);
}

void print_symbol_table(symbol_table_t* symbol_table, int indentation) {
  if (symbol_table == NULL) {
    return;
  }

  printf("\n%*sSymbol Table: %s\n", indentation, "", symbol_table->scope_id);
  printf("%*s------------------------------------------------------------------------------------\n", indentation, "");

  if (symbol_table->entries == NULL) {
      printf("%*s|                                       EMPTY                                      |\n", indentation, "");
      printf("%*s------------------------------------------------------------------------------------\n", indentation, "");
  } else {
    // Iterates through every symbol table entry
    symbol_table_entry_t * entry;
    DL_FOREACH(symbol_table->entries, entry) {
      printf("%*s|%-32s | %-12s | %-32s|\n", indentation, "", entry->id, entry->data_type, symbol_table->scope_id);
      printf("%*s------------------------------------------------------------------------------------\n", indentation, "");
    }

    inner_scope_t* inner_scope;
    DL_FOREACH(symbol_table->inner_scopes, inner_scope) {
      print_symbol_table(inner_scope->symbol_table, indentation + 2);
    }
  }
}

scope_stack_element_t* add_element_to_stack(scope_stack_element_t* head, char* scope_id) {
  scope_stack_element_t* new_scope_stack_element = (scope_stack_element_t*)malloc(sizeof(scope_stack_element_t));
  new_scope_stack_element->scope_id = strdup(scope_id);
  STACK_PUSH(head, new_scope_stack_element);
  return head;
}