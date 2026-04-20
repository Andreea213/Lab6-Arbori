#include <stdbool.h>
#include <limits.h> 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
};


struct node* insert(struct node* root, int data) {
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    
    if (root == NULL) {
        return newNode;
    }

    struct node* current = root;
    struct node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }

    
    if (data < parent->data) {
        parent->leftChild = newNode;
    } else {
        parent->rightChild = newNode;
    }

    return root;
}

bool esteBST(struct node* nod, long min, long max) {
    // 1. Condiția de oprire: un arbore gol este BST
    if (nod == NULL) {
        return true;
    }

    if (nod->data <= min || nod->data >= max) {
        return false;
    }

 
    return esteBST(nod->leftChild, min, nod->data) && 
           esteBST(nod->rightChild, nod->data, max);
}

 


int main() {
    struct node* root = NULL;

   
   int v[7] = {20, 10, 30, 5, 15, 25, 35};
    root = insert(root, 20);
    for (int i=1;i<7;i++)
        insert(root, v[i]);

  

if (esteBST(root, LONG_MIN, LONG_MAX)) {
        printf("Arborele este un BST valid!\n");
    } else {
        printf("Arborele NU este un BST valid.\n");
    }

    return 0;
}
