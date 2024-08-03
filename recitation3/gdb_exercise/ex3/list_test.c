#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>  

#include "list.h" 



int main() {
    struct node * head = 0; //head pointer for the list
    
    char * w1 = "hello";
    char * w2 = "cso201";
    char * w3 = "students";
    
    //no need to create nodes, the add function does it 
    addFront ( w1, &head);
    addFront ( w2, &head);
    addFront ( w3, &head);
    
    //obtain pointer (a second copy) to the front node
    // (why can't we just use the head pointer in the
    // loop below ???)
    struct node * current = head;
    
    //iterate through the list and print values stored in it
    while (current != 0 ) {
        printf ("%s     ", current->word );
        current = current->next;
    }
    printf("\n");
    
    char * w = removeFront(&head);
    
    //iterate through the list and print values stored in it
    printf("List content after removal: \n"); 
    current = head;
    while (current != 0 ) {
        printf ("%s     ", current->word );
        current = current->next;
    }
    printf("\n");
    printf("Removed value: %s\n", w); 
    
    //remove remaining elements of the list
    while (head != 0 ) {
        removeFront(&head);
    }
    
    
    return 0;
}



