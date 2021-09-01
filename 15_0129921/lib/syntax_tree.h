#ifndef SYNTAX_TREE_H_INCLUDED
#define SYNTAX_TREE_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utlist.h"

typedef struct node node_t;

// Node definition for AST
struct node {
  char* name;
  node_t* prev;
  node_t* next;
  node_t* node_list;
};

void add_node(node_t*, node_t*);
node_t* initialize_node(char*);
void print_syntax_tree(node_t*, int);
void free_syntax_tree(node_t*);

node_t* syntax_tree;

#endif