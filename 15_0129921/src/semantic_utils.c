#include "semantic_utils.h"

// This helper functions counts the number of arguments in a function call recursively
int count_number_of_arguments(node_t* args_list) {  
  if (args_list->node_list == NULL || strcmp(args_list->name, "args") != 0) {
    return 0;
  }

  return 1 + count_number_of_arguments(args_list->node_list);
}

// This function simply counts the position of the inner scope entry
int get_inner_scope_position(char* id) {
  int inner_scope_position = 0;
  symbol_table_entry_t* entry;
  DL_FOREACH(symbol_table->entries, entry) {
    if (strcmp(entry->id, id) == 0) {
      return inner_scope_position;
    }
  }
  return -1;
}

// This helper function searches for a symbol table inner scope in the global scope symbol table
symbol_table_t* get_function_symbol_table(char* id) {
  int inner_scope_position = get_inner_scope_position(id);

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

// Given a symbol table and its entry number, this function returns the nth argument. Warning: this function expects you to know the number of arguments!
symbol_table_entry_t* get_function_argument(char* function_id, int position) {
  symbol_table_t* function_symbol_table = get_function_symbol_table(function_id);
  int count = 0;

  symbol_table_entry_t* entry;
  DL_FOREACH(function_symbol_table->entries, entry) {
    if (count == position) {
      return entry;
    }
    count++;
  }
  return NULL;
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
int check_unary_operation_type(node_t* operator) {
  printf("->%s\n", operator->name);

  node_t* operand = operator->node_list;
  if (operand->type == NULL) {
    return 0;
  }
  operator->is_function = 0;

  // The operand cannot be a function id
  if (operand->is_function == 1) {
    return 0;
  }
  // No unary operations can be applied to NIL type
  if (strcmp(operand->type, LIST_TYPE_STR) == 0) {
    return 0;
  }
  // When the the operator is for logical negation, the type is int since the values are either 0 or 1
  if (strcmp(operator->name, "!") == 0) {
    if (strcmp(operand->type, FLOAT_TYPE_STR) == 0 || strcmp(operand->type, INT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      return 1;
    }
    if (strcmp(operand->type, FLOAT_LIST_TYPE_STR) == 0 || strcmp(operand->type, INT_LIST_TYPE_STR) == 0) {
      operator->type = operand->type;
      return 1;
    }
  } 
  if (strcmp(operator->name, "+") == 0 || strcmp(operator->name, "-") == 0) {
    // + - cannot be applied to lists
    if (strcmp(operand->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand->type, FLOAT_LIST_TYPE_STR) == 0) {
      return 0;
    }
    if (strcmp(operand->type, INT_TYPE_STR) == 0 || strcmp(operand->type, FLOAT_TYPE_STR) == 0) {
      operator->type = operand->type;
      return 1;
    }
  }
  if (strcmp(operator->name, "?") == 0 || strcmp(operator->name, "%") == 0) {
    // list operations cannot be applied to int or float
    if (strcmp(operand->type, INT_TYPE_STR) == 0 || strcmp(operand->type, FLOAT_TYPE_STR) == 0) {
      return 0;
    }
    if (strcmp(operator->name, "?") == 0) {
      if (strcmp(operand->type, INT_LIST_TYPE_STR) == 0) {
        operator->type = INT_TYPE_STR;
        return 1;
      }
      if (strcmp(operand->type, FLOAT_LIST_TYPE_STR) == 0) {
        operator->type = FLOAT_TYPE_STR;
        return 1;
      }
    }
    if (strcmp(operator->name, "%") == 0) {
      operator->type = operand->type;
      return 1;
    }
  }
  return 0;
}

/*
  This function checks for binary operation typing. It performs automatic casting in case the operands are int and float, otherwise
  it returns an error since it's undefined behaviour
*/
int check_binary_operation_type(node_t* operator) {
  int count = 0;
  node_t* operand1;
  node_t* operand2;
  
  // Retrieves the two operands from parent node
  node_t* child;
  DL_FOREACH(operator->node_list, child) {
    if (count == 0) {
      operand1 = child;
    } else {
      operand2 = child;
    }
    count++;
  }
  if (operand1->type == NULL || operand2->type == NULL) {
    return 0;
  }

  printf("binary %s %s %s\n", operand1->name, operator->name, operand2->name);
  printf("binary %s %s %s\n", operand1->type, operator->type, operand2->type);

  // All binary operations return variables
  operator->is_function = 0;

  // = Attribution
  if (strcmp(operator->name, "=") == 0) {
    // Checks for invalid operation between function and binary operations
    if (operand1->is_function == 1 || operand2-> is_function == 1) {
      return 0;
    }
    // For NIL the right operand must receive the type of the left operand in case of int list or float list, otherwise it is undefined
    if (strcmp(operand2->type, LIST_TYPE_STR) == 0) {
      if (strcmp(operand1->type, INT_TYPE_STR) == 0 || strcmp(operand1->type, FLOAT_TYPE_STR) == 0) {
        return 0;
      }
      if (strcmp(operand1->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand1->type, FLOAT_LIST_TYPE_STR) == 0) {
        operand2->type = operand1->type;
        operator->type = operand1->type;
        return 1;
      }
    }

    // In case of list operand1
    if (strcmp(operand1->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand1->type, FLOAT_LIST_TYPE_STR) == 0) {
      // int list and float list can only be assigned to the same type
      if (strcmp(operand1->type, operand2->type) != 0) {
        return 0;
      }
      // otherwise it has the same type of both operands
      operator->type = operand1->type;
      return 1;
    }

    // For int and float we must accept other its and float and add a conversion node if needed
    if(strcmp(operand1->type, FLOAT_TYPE_STR) == 0 || strcmp(operand1->type, INT_TYPE_STR) == 0) {
      // In case it's not int or float, the operation is undefined
      if (strcmp(operand2->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand2->type, FLOAT_LIST_TYPE_STR) == 0 || strcmp(operand2->type, LIST_TYPE_STR) == 0) {
        return 0;
      }

      if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0 && strcmp(operand2->type, INT_TYPE_STR) == 0) {
        operator->type = FLOAT_TYPE_STR;
        node_t* conversion_node = initialize_node(INT_TO_FLOAT_STR);
        conversion_node->type = FLOAT_TYPE_STR;
        conversion_node->is_function = 0;
        add_node_between(operator, conversion_node, operand2, 1);
        return 1;
      }

      if (strcmp(operand1->type, INT_TYPE_STR) == 0 && strcmp(operand2->type, FLOAT_TYPE_STR) == 0) {
        operator->type = INT_TYPE_STR;
        node_t* conversion_node = initialize_node(FLOAT_TO_INT_STR);
        conversion_node->type = INT_TYPE_STR;
        conversion_node->is_function = 0;
        add_node_between(operator, conversion_node, operand2, 1);
        return 1;
      }
      if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0 && strcmp(operand2->type, FLOAT_TYPE_STR) == 0) {
        operator->type = FLOAT_TYPE_STR;
        return 1;
      }
      if (strcmp(operand1->type, INT_TYPE_STR) == 0 && strcmp(operand2->type, INT_TYPE_STR) == 0) {
        operator->type = INT_TYPE_STR;
        return 1;
      }
    }
  }

  // &&, ||
  if (strcmp(operator->name, "&&") == 0 || strcmp(operator->name, "||") == 0) {
    // Checks for invalid operation between function and binary operations
    if (operand1->is_function == 1 || operand2-> is_function == 1) {
      return 0;
    }
    // In case operands are invalid, it returns an error
    if (strcmp(operand1->type, LIST_TYPE_STR) == 0 || strcmp(operand1->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand1->type, FLOAT_LIST_TYPE_STR) == 0 ||
        strcmp(operand2->type, LIST_TYPE_STR) == 0 || strcmp(operand2->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand2->type, FLOAT_LIST_TYPE_STR) == 0) {
      return 0;
    }
    // If operands are float and integer, then the integer value must be converted to float
    if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0 && strcmp(operand2->type, INT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      node_t* conversion_node = initialize_node(INT_TO_FLOAT_STR);
      conversion_node->type = FLOAT_TYPE_STR;
      conversion_node->is_function = 0;
      add_node_between(operator, conversion_node, operand2, 1);
      return 1;
    }
    if (strcmp(operand1->type, INT_TYPE_STR) == 0 && strcmp(operand2->type, FLOAT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      node_t* conversion_node = initialize_node(INT_TO_FLOAT_STR);
      conversion_node->type = FLOAT_TYPE_STR;
      conversion_node->is_function = 0;
      add_node_between(operator, conversion_node, operand1, 0);
      return 1;
    }
    if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0 && strcmp(operand2->type, FLOAT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      return 1;
    }
    if (strcmp(operand1->type, INT_TYPE_STR) == 0 && strcmp(operand2->type, INT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      return 1;
    }
  }

  // >, <, <=, >=, ==, !=
  if (strcmp(operator->name, ">") == 0 || strcmp(operator->name, "<") == 0 || strcmp(operator->name, "<=") == 0 ||
      strcmp(operator->name, ">=") == 0 || strcmp(operator->name, "==") == 0 || strcmp(operator->name, "!=") == 0) {
    
    // Relational operations will return an integer type that can be 0 or 1
    operator->type = INT_LIST_TYPE_STR;
    // Checks for invalid operation between function and binary operations
    if (operand1->is_function == 1 || operand2-> is_function == 1) {
      return 0;
    }

    // In case NIL is the first operand
    if (strcmp(operand1->type, LIST_TYPE_STR) == 0) {
      if (strcmp(operand2->type, FLOAT_LIST_TYPE_STR) == 0) {
        operand1->type = FLOAT_LIST_TYPE_STR;
      }
      else if (strcmp(operand2->type, INT_LIST_TYPE_STR) == 0) {
        operand2->type = INT_LIST_TYPE_STR;
      }
    }
    // In case NIL is the second operand
    if (strcmp(operand2->type, LIST_TYPE_STR) == 0) {
      if (strcmp(operand1->type, FLOAT_LIST_TYPE_STR) == 0) {
        operand1->type = FLOAT_LIST_TYPE_STR;
      }
      else if (strcmp(operand1->type, INT_LIST_TYPE_STR) == 0) {
        operand1->type = INT_LIST_TYPE_STR;
      }
    }

    // When comparing two list types, they must be of the same type
    if (strcmp(operand1->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand1->type, FLOAT_LIST_TYPE_STR) == 0) {
      if (strcmp(operand1->type, operand2->type) != 0) {
        return 0;
      }
    }

    // If operands are float and integer, then the integer value must be converted to float
    if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0 && strcmp(operand2->type, INT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      node_t* conversion_node = initialize_node(INT_TO_FLOAT_STR);
      conversion_node->type = FLOAT_TYPE_STR;
      conversion_node->is_function = 0;
      add_node_between(operator, conversion_node, operand2, 1);
      return 1;
    }
    if (strcmp(operand1->type, INT_TYPE_STR) == 0 && strcmp(operand2->type, FLOAT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      node_t* conversion_node = initialize_node(INT_TO_FLOAT_STR);
      conversion_node->type = FLOAT_TYPE_STR;
      conversion_node->is_function = 0;
      add_node_between(operator, conversion_node, operand1, 0);
      return 1;
    }
    if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0 && strcmp(operand2->type, FLOAT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      return 1;
    }
    if (strcmp(operand1->type, INT_TYPE_STR) == 0 && strcmp(operand2->type, INT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      return 1;
    }
  }

  // +, -, *, / operations can only be done for int and float
  if (strcmp(operator->name, "+") == 0 || strcmp(operator->name, "-") == 0 || strcmp(operator->name, "*") == 0 || strcmp(operator->name, "/") == 0) {
    // Checks for invalid operation between function and binary operations
    if (operand1->is_function == 1 || operand2-> is_function == 1) {
      return 0;
    }
    // In case operands are invalid, it returns an error
    if (strcmp(operand1->type, LIST_TYPE_STR) == 0 || strcmp(operand1->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand1->type, FLOAT_LIST_TYPE_STR) == 0 ||
        strcmp(operand2->type, LIST_TYPE_STR) == 0 || strcmp(operand2->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand2->type, FLOAT_LIST_TYPE_STR) == 0) {
      return 0;
    }
    // The following two cases add a conversion node in case operands are not of the same type
    if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0 && strcmp(operand2->type, INT_TYPE_STR) == 0) {
      operator->type = FLOAT_TYPE_STR;
      node_t* conversion_node = initialize_node(INT_TO_FLOAT_STR);
      conversion_node->type = FLOAT_TYPE_STR;
      conversion_node->is_function = 0;
      add_node_between(operator, conversion_node, operand2, 1);
      return 1;
    }
    if (strcmp(operand1->type, INT_TYPE_STR) == 0 && strcmp(operand2->type, FLOAT_TYPE_STR) == 0) {
      operator->type = FLOAT_TYPE_STR;
      node_t* conversion_node = initialize_node(INT_TO_FLOAT_STR);
      conversion_node->type = FLOAT_TYPE_STR;
      conversion_node->is_function = 0;
      add_node_between(operator, conversion_node, operand1, 0);
      return 1;
    }
    if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0 && strcmp(operand2->type, FLOAT_TYPE_STR) == 0) {
      operator->type = FLOAT_TYPE_STR;
      return 1;
    }
    if (strcmp(operand1->type, INT_TYPE_STR) == 0 && strcmp(operand2->type, INT_TYPE_STR) == 0) {
      operator->type = INT_TYPE_STR;
      return 1;
    }
  }
  // List filter and map
  else if (strcmp(operator->name, "<<") == 0 || strcmp(operator->name, ">>") == 0) {
    // The second operand must always be a int list type or float list type
    if (strcmp(operand2->type, FLOAT_LIST_TYPE_STR) != 0 && strcmp(operand2->type, INT_LIST_TYPE_STR) != 0) {
      return 0;
    }
    // The first argument must always be a function type (not function call type). The function must be unary (single argument)
    if (operand1->is_function != 1 && count_number_of_arguments(operand1) != 1) {
      return 0;
    }
    // The first argument must always be int or float since there are list of lists
    if (strcmp(operand1->type, FLOAT_TYPE_STR) != 0 && strcmp(operand1->type, INT_TYPE_STR) != 0) {
      return 0;
    }
    // Filter must return the same type of the second operand
    if (strcmp(operator->name, "<<") == 0) {
      operator->type = operand2->type;
      return 1;
    }
    // Map must return the type of the first operand's argument
    if (strcmp(operator->name, ">>") == 0) {
      if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0) {
        operator->type = FLOAT_LIST_TYPE_STR;
      }
      else {
        operator->type = INT_LIST_TYPE_STR;
      }
      return 1;
    }
  }
  // List constructor
  else if (strcmp(operator->name, ":") == 0) {
    // Checks for invalid operation between function and binary operations
    if (operand1->is_function == 1 || operand2-> is_function == 1) {
      return 0;
    }
    // The second operand must always be a int list type or float list type or NIL
    if (strcmp(operand2->type, FLOAT_LIST_TYPE_STR) != 0 && strcmp(operand2->type, INT_LIST_TYPE_STR) != 0 && strcmp(operand2->type, LIST_TYPE_STR) != 0) {
      return 0;
    }
    // The first operand must not be int list, float list or NIL
    if (strcmp(operand1->type, FLOAT_LIST_TYPE_STR) == 0 || strcmp(operand1->type, INT_LIST_TYPE_STR) == 0 || strcmp(operand1->type, LIST_TYPE_STR) == 0) {
      return 0;
    }
    // When NIL is the second operand its type must be redefined as a list of the first operand's type
    if (strcmp(operand2->type, LIST_TYPE_STR) == 0) {
      if (strcmp(operand1->type, FLOAT_TYPE_STR) == 0) {
        operand2->type = FLOAT_LIST_TYPE_STR;
      }
      else if (strcmp(operand1->type, INT_TYPE_STR) == 0) {
        operand2->type = INT_LIST_TYPE_STR;
      }
    }
    // When we have a float list type being constructed
    if (strcmp(operand2->type, FLOAT_LIST_TYPE_STR) == 0) {
      operator->type = FLOAT_LIST_TYPE_STR;
      // If the first operand's type is int, it must be converted to float
      if (strcmp(operand1->type, INT_TYPE_STR) == 0) {
        node_t* conversion_node = initialize_node(INT_TO_FLOAT_STR);
        conversion_node->type = FLOAT_TYPE_STR;
        conversion_node->is_function = 0;
        add_node_between(operator, conversion_node, operand1, 0);
      }
      return 1;
    }
    if (strcmp(operand2->type, INT_LIST_TYPE_STR) == 0) {
      operator->type = INT_LIST_TYPE_STR;
      // If the first operand's type is float, it must be converted to int
      if (strcmp(operand1->type, INT_TYPE_STR) == 0) {
        node_t* conversion_node = initialize_node(FLOAT_TO_INT_STR);
        conversion_node->type = INT_TYPE_STR;
        conversion_node->is_function = 0;
        add_node_between(operator, conversion_node, operand1, 0);
      }
      return 1;
    }
  }

  // Returns error if no previous match accepted
  return 0;
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
    // In case the id is found in one of the params it means this param was already declared previously in the same function declaration
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

// This function check if main was declared in the global symbol table and if its type is function
int check_main_declaration() {
  symbol_table_entry_t * entry;
  DL_FOREACH(symbol_table->entries, entry) {
    if (strcmp(entry->id, "main") == 0) {
      if (entry->is_function) {
        return 1;
      }
    }
  }
  printf("semantic error: function main was not declared\n");
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