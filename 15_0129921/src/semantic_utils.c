#include "semantic_utils.h"

// This helper functions counts the number of arguments in a function call recursively
int count_number_of_arguments(node_t* args_list) {  
  if (args_list->node_list == NULL || strcmp(args_list->name, "args") != 0) {
    return 0;
  }

  return 1 + count_number_of_arguments(args_list->node_list);
}

// This function simply counts the position of the inner scope entry
int get_inner_scope_position(symbol_table_t* symbol_table, char* id, int* params_count) {
  int inner_scope_position = 0;
  symbol_table_entry_t* entry;
  DL_FOREACH(symbol_table->entries, entry) {
    if (strcmp(entry->id, id)) {
      *params_count = entry->params_count;
      return inner_scope_position;
    }
  }
  return -1;
}

// This helper function searches for a symbol table inner scope in the global scope symbol table
symbol_table_t* search_for_function_symbol_table(symbol_table_t* symbol_table, char* id, int* params_count) {
  int inner_scope_position = get_inner_scope_position(symbol_table, id, params_count);

  int inner_scope_count = 0;
  inner_scope_t* inner_scope;
  DL_FOREACH(symbol_table->inner_scopes, inner_scope) {
    if (inner_scope_count == inner_scope_position) {
      return inner_scope->symbol_table;
    }
    inner_scope_count++;
  }
  return symbol_table;
}

// This function searches for an entry in a symbol table. In case the entry is found it returns 1, otherwise it returns 0
int find_entry_in_symbol_table(symbol_table_t* current_symbol_table, node_t* node) {
  // In case there is no parent, it means the id being used was not found in the symbol table and false is returned
  if (current_symbol_table == NULL) {
    return 0;
  }

  symbol_table_entry_t* entry;
  DL_FOREACH(current_symbol_table->entries, entry) {
    // In case the id is found in one of the entries it means the scope is valid
    if (strcmp(entry->id, node->name) == 0) {
      node->type = entry->data_type;
      node->is_function = entry->is_function;
      return 1;
    }
  }

  // If the id is not found in the current symbol table node, it tries searching for an entry in an upper scope
  return find_entry_in_symbol_table(current_symbol_table->parent, node);
}

/*
  This checks for the type in the first child of an unary operation and adds it to the unary operator node
  If the operand is a function it returns an error
*/
int check_unary_operation_type(node_t* node) {
  node_t* head = node->node_list;
  node->is_function = head->is_function;
  // When the the operator is for logical negation, the type is int since the values are either 0 or 1
  if ((strcmp(node->name, "!") == 0) && (strcmp(head->type, "float") == 0 || strcmp(head->type, "int") == 0)) {
    node->type = INT_TYPE_STR;
  } else {
    node->type = head->type;
  }

  // Checks for invalid operation between function and unary operations
  if (node->is_function == 1) {
    return 0;
  }
  // No operations can be applied no NIL type
  if (strcmp(node->type, "list") == 0) {
    return 0;
  }
  // + - cannot be applied to lists
  if ((strcmp(node->name, "+") == 0 || strcmp(node->name, "-") == 0) && (strcmp(node->type, "int list") == 0 || strcmp(node->type, "float list") == 0)) {
    return 0;
  }
  // list operations cannot be applied to int or float
  if ((strcmp(node->name, "?") == 0 || (strcmp(node->name, "%") == 0)) && (strcmp(node->type, "int") == 0 || strcmp(node->type, "float") == 0)) {
    return 0;
  }
  return 1;
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

// This function searches for an id in the temp params list, in case it finds an id in the temp params list, it returns 1, otherwise it returns 0
int check_redeclared_param(char* id) {
  func_param_t * param;
  DL_FOREACH(func_params_list, param) {
    // In case the id is found in one of the params it means this param was already declared previously in the same function dedclaration
    if (strcmp(param->id, id) == 0) {
      return 1;
    }
  }
  return 0;
}

/*
  This functions checks in the global scope symbol table if the function declaration has the same number of arguments as 
  the function call. WARNING: This function expects that you have checked if the function was declared previously!
*/
int check_number_of_arguments(symbol_table_t* symbol_table, char* id, node_t* args_list) {
  // Count number of args in function call
  int args_count = count_number_of_arguments(args_list);

  // Search for function declaration and get the number of params specified in the declaration
  int params_count = -1;
  symbol_table_entry_t * entry;
  DL_FOREACH(symbol_table->entries, entry) {
    if (strcmp(entry->id, id) == 0) {
      params_count = entry->params_count;
    }
  }

  if (args_count == params_count) {
    return 1;
  }
  return 0;
}

// int compare_arg_types_to_entry_types(char* data_type, node_t* args_list, int depth) {

// }

// int check_type_of_arguments(symbol_table_t* symbol_table, char* id, node_t* args_list) {
//   int params_count;
//   symbol_table_t* function_symbol_table = search_for_function_symbol_table(symbol_table, id, &params_count);

//   int depth = 0;
//   symbol_table_entry_t* entry;
//   DL_FOREACH(symbol_table->entries, entry) {
//     if (depth < params_count) {
//       compare_arg_types_to_entry_types(entry->data_type, args_list, depth);
//     }
//     depth++;
//   }
//   return compare_arg_types_to_entry_types(function_symbol_table, args_list);
// }