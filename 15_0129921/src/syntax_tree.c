#include "syntax_tree.h"

void add_node(node_t* parent, node_t* child) {
  // printf("add node %s %s\n", parent->name, child->name);
  DL_APPEND(parent->node_list, child);
}

node_t* initialize_node(char* name) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->node_list = NULL;
  node->name = strdup(name);
  // printf("initialize_node %s\n", node->name);
  return node;
}

void print_syntax_tree(node_t* node, int indent) {
  if (node == NULL) {
    return;
  }

  printf("%*s%s\n", indent, "", node->name);

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