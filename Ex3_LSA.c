#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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


struct node* gasesteLCA(struct node* current, int p, int q) {
    if (current == NULL) {
        return NULL;
    }

    if (current->data == p || current->data == q) {
        return current;
    }

    struct node* stanga = gasesteLCA(current->leftChild, p, q);
    struct node* dreapta = gasesteLCA(current->rightChild, p, q);

    if (stanga != NULL && dreapta != NULL) {
        return current;
    }

    if (stanga != NULL) {
        return stanga;
    } else {
        return dreapta;
    }
}


int main() {
    struct node* root = NULL;

   
   int v[7] = {20, 10, 30, 5, 15, 25, 35};
    root = insert(root, 20);
    for (int i=1;i<7;i++)
        insert(root, v[i]);
  
    int val1 = 5, val2 = 15;
    struct node* stramos = gasesteLCA(root, val1, val2);

    if (stramos != NULL) {
        printf("Cel mai apropiat stramos comun pentru %d si %d este: %d\n", val1, val2, stramos->data);
    }

    val1 = 5; val2 = 35;
    stramos = gasesteLCA(root, val1, val2);
    if (stramos != NULL) {
        printf("Cel mai apropiat stramos comun pentru %d si %d este: %d\n", val1, val2, stramos->data);
    }

    return 0;
}
