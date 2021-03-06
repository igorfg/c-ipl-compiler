#ifndef SYNTAX_TREE_H_INCLUDED
#define SYNTAX_TREE_H_INCLUDED
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol_table.h"
#include "utlist.h"

typedef struct node node_t;
typedef struct node_recovery node_recovery_t;

// Node definition for AST
struct node {
  char* name;
  node_t* prev;
  node_t* next;
  node_t* node_list;
  char* type;
  int is_function;
  int line;
  int col;
};

struct node_recovery {
  node_t* node;
  node_recovery_t* prev;
  node_recovery_t* next;
};

void add_node(node_t*, node_t*);
node_t* initialize_node(char*, int, int);
void print_syntax_tree(node_t*, int);
void free_syntax_tree(node_t*);
void add_node_to_error_recovery_list(node_t*);
void free_error_recovery_list();
void add_node_between(node_t*, node_t*, node_t*, int);
int check_main_declaration();

node_t* syntax_tree;
node_recovery_t* error_recovery_node_list;

#endif