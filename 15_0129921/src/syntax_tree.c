#include "syntax_tree.h"

void add_node(node_t* parent, node_t* child) {
  // printf("add node %s %s\n", parent->name, child->name);
  DL_APPEND(parent->node_list, child);
}

node_t* initialize_node(char* name) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->node_list = NULL;
  node->name = strdup(name);
  node->type = NULL;
  node->is_function = -1;
  // printf("initialize_node %s\n", node->name);
  add_node_to_error_recovery_list(node);
  return node;
}

void print_syntax_tree(node_t* node, int indent) {
  if (node == NULL) {
    return;
  }

  if (node->is_function == -1) {
    printf("%*s%s\n", indent, "", node->name);
  } else if (node->is_function == 0) {
    printf("%*s%s [Type: %s]\n", indent, "", node->name, node->type);
  } else {
    printf("%*s%s [Type: Function][Return Type: %s]\n", indent, "", node->name, node->type);
  }

  node_t* child;
  DL_FOREACH(node->node_list, child) {
    print_syntax_tree(child, indent+2);
  }
}

void free_syntax_tree(node_t* node) {
  if (node == NULL) {
    return;
  }

  node_t* child;
  node_t* tmp_child;
  DL_FOREACH_SAFE(node->node_list, child, tmp_child) {
    DL_DELETE(node->node_list, child);
    free_syntax_tree(child);
  }
  // printf("free %s\n", node->name);
  free(node->name);
  free(node);
}

void add_node_to_error_recovery_list(node_t* node) {
  node_recovery_t* node_recovery = (node_recovery_t*)malloc(sizeof(node_recovery_t));
  node_recovery->node = node;
  DL_APPEND(error_recovery_node_list, node_recovery);
}

void free_error_recovery_list() {
  node_recovery_t* node_recovery;
  node_recovery_t* tmp_node_recovery;
  DL_FOREACH_SAFE(error_recovery_node_list, node_recovery, tmp_node_recovery) {
    free(node_recovery->node->name);
    free(node_recovery->node);
    DL_DELETE(error_recovery_node_list, node_recovery);
    free(node_recovery);
  }
}