#include "list.h"


void print_list(node_t *root) {
	node_t * temp = root;
	if (root == NULL) {
		printf("[]\n");
		return;
	}
	printf("[");
	while(temp) {
		if (temp->next == NULL) {
			printf("%d]\n", temp->val);
			return;
		} else {
			printf("%d, ", temp->val);
			temp = temp->next;
		}
	}
}

node_t * node_alloc(int data, node_t *point_to) {
	node_t *new_node = (node_t*) malloc(sizeof(node_t));
	if (new_node == NULL) {
		fprintf(stderr, "Memory allocation failed for node_alloc, terminating..\n");
		exit(1);
	}
	new_node->val = data;
	new_node->next = point_to;
	return new_node;
}

void add_end(node_t **root, int data) {
	node_t * temp = *root;
	if (*root == NULL) {
		*root = node_alloc(data, NULL);
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = node_alloc(data, NULL);
	return;
}

void add_start(node_t **root, int data) {
	node_t * new_node = NULL;
	new_node = node_alloc(data, *root);
	*root = new_node;
	return;
}

void add_after(node_t **root, int data, int lookout) {
	node_t * temp = *root;
	node_t * node_after = NULL;
	if (*root == NULL) {
		printf("ERROR: The searched element was not found. Exitting..\n");
		exit(1);
	}
	while (temp != NULL && temp->val != lookout) {
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("ERROR: The searched element was not found. Exitting..\n");
		exit(1);
	}
	node_after = node_alloc(data, temp->next);
	temp->next = node_after;
	return;
}

void print_index(node_t **root, int data) {
	int index = 0;
	node_t * temp = *root;
	if (root == NULL) {
		printf("-1\n");
		return;
	}
	while (temp != NULL) {
		if (temp->val == data) {
			printf("%d\n", index);
			return;
		} else {
			index++;
			temp = temp->next;
		}
	}
	printf("-1\n");
	return;
}
void delete_index(node_t **root, int index) {
	node_t * temp = *root;
	node_t * prev = NULL;
	if (root == NULL) {
		printf("ERROR: index is out-of-bound. Exitting..\n");
		exit(1);
	}
	while (temp != NULL) {
		if (index == 0) {
			if (prev == NULL) {
				*root = temp->next;
			} else {
				prev->next = temp->next;
			}
		free(temp);
		return;
		}
		index--;
		prev = temp;
		temp = temp->next;
	}
	printf("ERROR: index is out-of-bound. Exitting..\n");
	exit(1);
}

bool compare_lists(node_t *list1, node_t *list2) {
	node_t *comp1 = list1;
	node_t *comp2 = list2;
	while(comp1 != NULL && comp2 != NULL) {
		if (comp1->val != comp2->val) {
			return false;
		}
		comp1 = comp1->next;
		comp2 = comp2->next;
	}
	if (comp1 == NULL && comp2 == NULL) {
		return true;
	} else {
		return false;
	}
}

void reverse_list(node_t **root) {
	node_t *nex = (*root)->next;
	node_t *prev = NULL;
	while(nex != NULL) {
		(*root)->next = prev;
		prev = *root;
		*root = nex;
		nex = nex->next;
	}
	(*root)->next = prev;
	return;
}

void isListPalindrome(node_t *root) {
	node_t *first_half = root;
	node_t *middle = NULL;
	node_t *second_half = root;
	node_t *prev_of_second_half = root;
	node_t *temp = root;
	if (root == NULL || root->next == NULL) {
		printf("Yes. The list represents a palindrome number!\n");
		return;
	}
	while (temp != NULL && temp->next != NULL) {
		prev_of_second_half = second_half;
		temp = (temp->next)->next;
		second_half = second_half->next;
	}
	if (temp != NULL) {
		middle = second_half;
		second_half = second_half->next;
	}
	prev_of_second_half->next = NULL;
	reverse_list(&first_half);
	if (compare_lists(first_half, second_half) == true) {
		printf("Yes. The list represents a palindrome number!\n");
	} else {
		printf("No. The list doesn't represent a palindrome number!\n");
	}
	reverse_list(&first_half);
	if (temp != NULL) {
		prev_of_second_half->next = middle;
	} else {
		prev_of_second_half->next = second_half;
	}
	return;
}
