#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#define INPUT_SIZE 100


void free_list(node_t *root) {
	if (root == NULL) {
		return;
	}
	free_list(root->next);
	free(root);
}

void user_interface() {
	int exit = 0;
	int i;
	char input[INPUT_SIZE];
	char *token;
	int num1 = NULL, num2 = NULL;
	node_t * root = NULL;
	printf("Command list:\n");
	printf ("Add_end i	– insert element I at end of list.\n");
	printf ("Add_start i	– insert element I at start of list.\n");
	printf ("Add_after i j	– insert element I after the first occurrence of element j.\n"); 
	printf("Index i		– print the first index where element I is found, -1 if not found. The first element starts at index 0\n");
	printf("Del index	– remove the element at the specified index.\n");
	printf("Palindrome	– Checks if the list represents a palindrome number.\n");
	printf("reverse		– Revereses the list.");
	printf("Print		– print the entire list.\n");
	printf("Exit		– exit the program.\n");
	while (exit != 1) {
		input[0] = '\0';
		num1 = NULL;
		num2 = NULL;
		printf("What would you like to do next?\n");
		scanf("%[^\n]%*c", input);
		for (i = 0; input[i]; i++) {
			input[i] = tolower(input[i]);
		}
		token = strtok(input, " ");
		if (strcmp(token, "exit") == 0) {
			free_list(root);
			exit = 1;
		} else if (strcmp(token, "palindrome") == 0) {
			isListPalindrome(root);
		} else if (strcmp(token, "print") == 0) {
			print_list(root);			
		} else if (strcmp(token, "reverse") == 0) {
			reverse_list(&root);
		} else if (strcmp(token, "add_end") == 0) {
			token = strtok(NULL, " ");
			if (token != NULL) {
				num1 = atoi(token);
				add_end(&root, num1);
			}
		} else if (strcmp(token, "add_start") == 0) {
			token = strtok(NULL, " ");
			if (token != NULL) {
				num1 = atoi(token);
				add_start(&root, num1);
			}
		} else if (strcmp(token, "index") == 0) {
			token = strtok(NULL, " ");
			if (token != NULL) {
				num1 = atoi(token);
				print_index(&root, num1);
			}
		} else if (strcmp(token, "add_after") == 0) {
			token = strtok(NULL, " ");
			if (token == NULL) {
				continue;
			}
			num1 = atoi(token);
			token = strtok(NULL, " ");
			if (token == NULL) {
				continue;
			}
			num2 = atoi(token);
			add_after(&root, num1, num2);
		} else if (strcmp(token, "del") == 0) {
			token = strtok(NULL, " ");
			if (token != NULL) {
				num1 = atoi(token);
				delete_index(&root, num1);
			}
		} else {
			printf("Wrong command, please try again!\n");
		}
	}
}


int main() {
	user_interface();
	return 0;
}
