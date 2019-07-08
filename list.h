#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int val;
	struct node *next;
} node_t;

node_t * node_alloc(int data, node_t *point_to);
void print_list(node_t *root);
void add_end(node_t **root, int data);
void add_start(node_t **root, int data);
void add_after(node_t **root, int data, int lookout);
void print_index(node_t **root, int data);
void delete_index(node_t **root, int index);
bool compare_lists(node_t *list1, node_t *list2);
void reverse_list(node_t **root);
void isListPalindrome(node_t *root);

#endif
