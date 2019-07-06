# Linked List
Linked list implementation w/ user intercation 

## The data structure
```C
typedef struct node {
  int val;
  struct node *next;
} node_t;
```

## User Interface
User can interact using these commands:

* Add_end i     – insert element I at end of list
* Add_start i   – insert element I at start of list
* Add_after i j – insert element I after the first occurrence of element j. If j is not found, print an error and exit the program
* Index i       – print the first index where element I is found, -1 if not found. The first element is index 0, the second is index 1, etc.
* Del index     – remove the element at the specified index. If index is too large, print an error and exit the program
* Print         – print the entire list. An empty list is printed as “[]”. A list with one element whose value is 1 is printed as “[1]”. A list with 3 elements, 1-3, is printed as “[1, 2, 3]”, with a space after each comma
* Exit          – exit the program


##### The interface will handle any capitalization given by the user, so all these commands are legal and equivalent:
- Add_start 1
- ADD_START 1
- add_start 1
- aDd_StArt 1

### Example
Add_end 1 // list is now [1]

Add_start 2 // [2, 1]

Add_after 3 2 // [2, 3, 1]

Index 3 // list is unchanged, result is 1 (remember – indices start at 0)

Del 2 // [2, 3]

Print // list is unchanged, prints [2, 3]

Exit // Hooray, we’re done!
