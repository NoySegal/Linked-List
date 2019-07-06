#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_SIZE 100

void user_interface() {
	int exit = 0;
	int i;
	char input[INPUT_SIZE];
	char *token;
	int num1, num2;
	printf("Command list:\n");
	printf ("Add_end i	– insert element I at end of list.\n");
	printf ("Add_start i	– insert element I at start of list.\n");
	printf ("Add_after i j	– insert element I after the first occurrence of element j.\n"); 
	printf("Index i		– print the first index where element I is found, -1 if not found. The first element starts at index 0\n");
	printf("Del index	– remove the element at the specified index.\n");
	printf("Print		– print the entire list.\n");
	printf("Exit		– exit the program\n");
	while (exit != 1) {
		input[INPUT_SIZE] = "";
		printf("What would you like to do next?\n");
		scanf("%[^\n]%*c", input);
		for (i = 0; input[i]; i++) {
			input[i] = tolower(input[i]);
		}
		token = strtok(input, " ");
		if (strcmp(token, "exit") == 0) {
			exit = 1;
		} else if (strcmp(token, "print") == 0) {
			
		} else if (strcmp(token, "add_end") == 0) {
			token = strtok(NULL, " ");
			num1 = atoi(token);
		} else if (strcmp(token, "add_start") == 0) {
			token = strtok(NULL, " ");
			num1 = atoi(token);
		} else if (strcmp(token, "index") == 0) {
			token = strtok(NULL, " ");
			num1 = atoi(token);
		} else if (strcmp(token, "add_after") == 0) {
			token = strtok(NULL, " ");
			num1 = atoi(token);
			token = strtok(NULL, " ");
			num2 = atoi(token);
		} else {
			printf("Wrong command, please try again!\n");
		}
/*		if (strstr(input, "add_end")) {
			num1 = atoi(input + 8);
		} else if (strstr(input, "add_start")) {
			num1 = atoi(input + 10);
		} else if (strstr(input, "add_after")) {
			num1 = atoi(input + 
		} else if (strstr(input, "index")) {

		} else if (strstr(input, "print")) {

		} else if (strstr(input, "exit")) {
			exit = 1;
		} else {
			printf("Wrong command, please try again!\n");
		}*/
			
	}
}


int main() {
	user_interface();
	return 0;
}
