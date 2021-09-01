#include "syntax_tree.h"

void add_node(node_t* parent, node_t* child) {
  DL_APPEND(parent->node_list, child);
}

node_t* initialize_node(char* name) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->node_list = NULL;
  node->name = strdup(name);
  return node;
}