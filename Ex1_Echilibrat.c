#include <stdbool.h>
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


int inaltime (struct node* nod)
{
    if (nod==NULL) return 0;
    int h_st=inaltime(nod->leftChild);
    int h_dr=inaltime(nod->rightChild);
    if (h_st>h_dr) return 1+h_st;
    return 1+h_dr;
}

bool echilibrat(struct node* nod)
{
    if (nod==NULL) return true;
    int l = inaltime(nod->leftChild);
    int r = inaltime(nod->rightChild);
   
    if (abs(l - r) <= 1 && echilibrat(nod->leftChild) && echilibrat(nod->rightChild))  return true;
    
    return false;
}    
int main() {
    struct node* root = NULL;
int v[7] = {20, 10, 30, 5, 15, 25, 35};
    root = insert(root, v[0]);
    for (int i = 1; i < 7; i++) {
        insert(root, v[i]);
    }

   
    if (echilibrat(root)) {
        printf("Rezultat: Arborele este echilibrat.\n");
    } else {
        printf("Rezultat: Arborele NU este echilibrat.\n");
    }

   
    return 0;
}


