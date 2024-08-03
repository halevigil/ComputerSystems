#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>   
#include "list.h" 

void addFront(char * word, struct node ** head) {
    //allocate memory for storying the node 
    struct node *n = (struct node *)malloc(sizeof(struct node));
    //make sure that the memory was allocated,
    //if not, just quit
    if (n == NULL)
        return;
    //set values of members to the string passed
    //and head of the list 
    n->word = word;
    n->next = (*head);
    //reset head to point to the new first node 
    (*head) = n;
}

// !!! this function has to deallocate memory when it
//     remove a node - otherwise we would have a memory leak 
char* removeFront(struct node ** head) {
    //check if the list is empty
    if (head == NULL )
        return NULL;
    //get the pointer to the first element
    struct node *n = *head;
    //get the first element 
    char *w = n->word;
    //advance head
    (*head) = n->next;
    //free memory allocated for n
    free(n);
    n = NULL; 
    //return the value stored in the node that was just removed 
    return w;
}
