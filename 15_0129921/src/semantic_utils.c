#include "semantic_utils.h"


// This function searches for an entry in a symbol table. In case the entry is found it returns 1, otherwise it returns 0
int search_for_entry_in_symbol_table(symbol_table_t* current_symbol_table, char* id) {
  // In case there is no parent, it means the id being used was not found in the symbol table and false is returned
  if (current_symbol_table == NULL) {
    return 0;
  }

  symbol_table_entry_t * entry;
  DL_FOREACH(current_symbol_table->entries, entry) {
    // In case the id is found in one of the entries it means the scope is valid
    if (strcmp(entry->id, id) == 0) {
      return 1;
    }
  }

  // If the id is not found in the current symbol table node, it tries searching for an entry in an upper scope
  return search_for_entry_in_symbol_table(current_symbol_table->parent, id);
}

// This function searches for an id in a single symbol table, in case it finds an id in its entry, it returns 1, otherwise it returns 0
int check_redeclared_id(symbol_table_t* symbol_table, char* id) {
  symbol_table_entry_t * entry;
  DL_FOREACH(current_symbol_table->entries, entry) {
    // In case the id is found in one of the entries it means this variable or function was already declared previously in the same scope
    if (strcmp(entry->id, id) == 0) {
      return 1;
    }
  }
  return 0;
}