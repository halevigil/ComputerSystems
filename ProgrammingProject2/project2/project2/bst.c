#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


/*
* Gil Halevi
* implemented all the below methods
*/

void add ( bst_node ** root, char * word ) {
    if ((*root)==0){
        bst_node * new = malloc(sizeof(struct bst_node)); // allocate new memory for the new node
        *new = (struct bst_node){word, 0,0};
        *root = new;
    } 
    else if (strcmp(word,(*root)->data)<0){
        add(&((*root)->left),word);
    } 
    else {
        add(&((*root)->right),word);
    }
}

 
void inorder ( bst_node * root ) {
    if (root==0){
        return;
    }
    inorder(root->left);
    printf("%s ",root->data);
    inorder(root->right);
}


 
char * removeSmallest (  bst_node ** root ){
    if (*root==0){
        return NULL;
    }
    if ((*root)->left==0){
        
        char * out = (*root)->data;
        struct bst_node * right=(*root)->right;
        free(*root); // clear the memory that was allocated previously
        *root = right;
        return out;
    }
    return removeSmallest(&((*root)->left));
}

 
char * removeLargest (  bst_node ** root ){
    if (*root==0){
        return NULL;
    }
    if ((*root)->right==0){
        char * out = (*root)->data;
        struct bst_node * left=(*root)->left;
        free(*root);// clear the memory that was allocated previously
        *root = left;
        return out;
    }
    return removeLargest(&((*root)->right));
}




