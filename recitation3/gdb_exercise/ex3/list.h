
/*
 * This program illustrates our second attempt at implementing
 * a linked list. 
 * This is a better way of doing so than the previous example:
 * the nodes are allocated dynamically by the add method,
 * the memory is deallocated when the nodes are removed by 
 * the remove method. 
 * This type of list can be easily passed between functions
 * and is using memory from the heap, not from the stack. 
 * 
 * Author: Joanna Klukowska 
 * 
 */ 


//linked list node 
struct node {
    char * word;
    struct node * next;
};

//adds the node pointed to by n to the front of the linked 
//list pointed to by head
// !!! note that since we need to change what head
//     points to, we need a pointer to it - yes that 
//     is a pointer to a pointer or a double pointer 
void addFront(char * word, struct node ** head);

//removes a node from the front of the linked list
//pointed to by head and returns the value that was stored
//in that node
// !!! again, this function needs to modify what head points to, 
//     so the head pointer needs to be passed using a 
//     double pointer 
char* removeFront(struct node ** head);
    
