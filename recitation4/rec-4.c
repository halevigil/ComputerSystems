#include <stdio.h>
#include <string.h>
struct node {
char * word;
struct node * next;
};

void addFront(struct node * n, struct node ** head);
void delete(struct node ** head, int i);
void DeleteIT(struct node **head, char* word);



void show(struct node ** head)
{
    struct node * current = *head;
    while (current != 0 ) {
    printf ("%s	", current->word ); current = current->next;
    }
    printf("\n");
}
void reverse(struct node ** head);

int main() {
struct node * head = 0; // head p o i n t e r for the list
struct node n1 = { "Hello", 0}; 
struct node n2 = { "a", 0}; 
struct node n3 = { "Hello", 0}; 
struct node n4 = { "Hello", 0}; 
struct node n5 = { "students", 0} ;
struct node n6 = { "Hello", 0}; 
 
 
addFront ( &n1, &head);
addFront ( &n2, &head); 
addFront ( &n3, &head);
addFront ( &n4, &head);
addFront ( &n5, &head);
addFront ( &n6, &head);
 

printf("original list:");
show(&head);
DeleteIT(&head,"Hello");
printf("delete Hello:");
show(&head);

return 0;
}
 
void DeleteIT(struct node **head, char* word){
    struct node** n = head;
    while ((*n)!=NULL){
        if (strcmp((*n)->word, word)==0){
        *n=(*n)->next;
        }
        else{
            n=&((*n)->next);
        }
    }
}
void addFront(struct node * n, struct node ** head) {
    n->next =   *head ;
    *head  = n;
    //printf ("%s	", (*head)->word ); 
}

void reverse(struct node ** head){
    struct node* prev;
    struct node* current = *head;
    struct node* next = (*head)->next;
    current->next = 0;
    while (next != 0){
        prev=current;
        current = next;
        next = next->next;
        current->next = prev;
    }
    *head=current;
}

//deletes the element at index i of the list, where the first element has index 0
void delete(struct node ** head, int i){
    struct node** n = head;
    while (i!=0){
        n=&((*n)->next);
        i--;
    }
    *n = (*n)->next;
}

void getLast(struct node * head){

}
 

 
 
