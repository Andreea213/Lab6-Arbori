#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *leftChild, *rightChild;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->leftChild = newNode->rightChild = NULL;
    return newNode;
}

int gasesteNivel(struct node* current, int val, int nivel) {
    if (current == NULL) return 0;
    if (current->data == val) return nivel;

    int n = gasesteNivel(current->leftChild, val, nivel + 1);
    if (n != 0) return n;

    return gasesteNivel(current->rightChild, val, nivel + 1);
}

bool suntFrati(struct node* current, int a, int b) {
    if (current == NULL) return false;

    if (current->leftChild != NULL && current->rightChild != NULL) {
        if ((current->leftChild->data == a && current->rightChild->data == b) ||
            (current->leftChild->data == b && current->rightChild->data == a)) {
            return true;
        }
    }

    return suntFrati(current->leftChild, a, b) || suntFrati(current->rightChild, a, b);
}

bool suntVerisori(struct node* root, int a, int b) {
    if (root == NULL) return false;
    
    int nivelA = gasesteNivel(root, a, 1);
    int nivelB = gasesteNivel(root, b, 1);
    
    if (nivelA == nivelB && !suntFrati(root, a, b)) {
        return true;
    }
    return false;
}

int main() {
    struct node* root = createNode(1);
    root->leftChild = createNode(2);
    root->rightChild = createNode(3);
    root->leftChild->leftChild = createNode(4);
    root->leftChild->rightChild = createNode(5);
    root->rightChild->leftChild = createNode(6);
    root->rightChild->rightChild = createNode(7);

    int x = 4, y = 6;
    if (suntVerisori(root, x, y)) {
        printf("%d si %d sunt verisori\n", x, y);
    } else {
        printf("%d si %d nu sunt verisori\n", x, y);
    }

    return 0;
}
