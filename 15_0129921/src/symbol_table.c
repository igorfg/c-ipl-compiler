#include "symbol_table.h"

symbol_table_t* initialize_symbol_table(int id) {
  symbol_table_t *new_symbol_table = NULL;
  new_symbol_table = (symbol_table_t*)malloc(sizeof(symbol_table_t));
  new_symbol_table->scope_id = id;
  new_symbol_table->parent = NULL;
  new_symbol_table->entries = NULL;
  new_symbol_table->inner_scopes = NULL;
  return new_symbol_table;
}

void add_symbol_table_entry(symbol_table_t* symbol_table, char* id, char* data_type, int is_function, int params_count) {
  symbol_table_entry_t *new_symbol_table_entry = NULL;
  new_symbol_table_entry = (symbol_table_entry_t*)malloc(sizeof(symbol_table_entry_t));
  new_symbol_table_entry->id = strdup(id);
  new_symbol_table_entry->data_type = strdup(data_type);
  new_symbol_table_entry->is_function = is_function;
  new_symbol_table_entry->params_count = params_count;
  DL_APPEND(symbol_table->entries, new_symbol_table_entry);
}

void add_symbol_table_to_inner_scope(symbol_table_t* parent, symbol_table_t* child) {
  child->parent = parent;
  inner_scope_t* inner_scope = (inner_scope_t*)malloc(sizeof(inner_scope_t));
  inner_scope->symbol_table = child;
  DL_APPEND(parent->inner_scopes, inner_scope);
}

void print_symbol_table(symbol_table_t* symbol_table, int indentation) {
  if (symbol_table == NULL) {
    return;
  }

  if (symbol_table->parent != NULL) {
    printf("\n%*sSymbol Table: %d, Parent Table: %d\n", indentation, "", symbol_table->scope_id, symbol_table->parent->scope_id);
  } else {
    printf("\n%*sSymbol Table: %d, Parent Table: None\n", indentation, "", symbol_table->scope_id);
  }
  printf("%*s----------------------------------------------------------------------------------------------\n", indentation, "");

  if (symbol_table->entries == NULL) {
    printf("%*s|                                            EMPTY                                           |\n", indentation, "");
    printf("%*s----------------------------------------------------------------------------------------------\n", indentation, "");
  } else {
    printf("%*s| %-32s | %-12s | %-12s | %12s |\n", indentation, "", "Identifier", "Data / Return Type", "Function / Variable", "Params count"
    );
    printf("%*s----------------------------------------------------------------------------------------------\n", indentation, "");

    // Iterates through every symbol table entry
    symbol_table_entry_t * entry;
    DL_FOREACH(symbol_table->entries, entry) {
      if (entry->is_function) {
        printf("%*s| %-32s | %-18s | %-19s | %-12d |\n", indentation, "", entry->id, entry->data_type, "function", entry->params_count);
      } else {
        printf("%*s| %-32s | %-18s | %-19s | %-12s | \n", indentation, "", entry->id, entry->data_type, "var", "N/A");
      }
      printf("%*s----------------------------------------------------------------------------------------------\n", indentation, "");
    }
  }

  inner_scope_t* inner_scope;
  DL_FOREACH(symbol_table->inner_scopes, inner_scope) {
    print_symbol_table(inner_scope->symbol_table, indentation + 2);
  }
}

void free_symbol_table(symbol_table_t* symbol_table) {
  if (symbol_table == NULL) {
    return;
  }

  inner_scope_t* inner_scope;
  inner_scope_t* tmp_inner_scope;
  DL_FOREACH_SAFE(symbol_table->inner_scopes, inner_scope, tmp_inner_scope) {
    free_symbol_table(inner_scope->symbol_table);
    DL_DELETE(symbol_table->inner_scopes, inner_scope);
    free(inner_scope);
  }

  // Frees every symbol table entry
  symbol_table_entry_t * entry;
  symbol_table_entry_t * tmp_entry;
  DL_FOREACH_SAFE(symbol_table->entries, entry, tmp_entry) {
    DL_DELETE(symbol_table->entries, entry);
    free(entry->id);
    free(entry->data_type);
    free(entry);
  }

  free(symbol_table);
}

void save_func_param(char* id, char* data_type) {
  func_param_t* param = (func_param_t*)malloc(sizeof(func_param_t));
  param->data_type = strdup(data_type);
  param->id = strdup(id);
  DL_APPEND(func_params_list, param);
  func_params_count++;
}

void add_params_to_symbol_table(symbol_table_t* symbol_table) {
  if (func_params_list != NULL) {    
    func_param_t* param;
    func_param_t* tmp;

    DL_FOREACH_SAFE(func_params_list, param, tmp) {
      add_symbol_table_entry(symbol_table, param->id, param->data_type, 0, -1);
      DL_DELETE(func_params_list, param);
      free(param->id);
      free(param->data_type);
      free(param);
    }
    func_params_list = NULL;
  }
}