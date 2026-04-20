#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void serialize(struct node* current, char* buffer) {
    if (current == NULL) {
        strcat(buffer, "#,");
        return;
    }

    char temp[20];
    sprintf(temp, "%d,", current->data);
    strcat(buffer, temp);

    serialize(current->leftChild, buffer);
    serialize(current->rightChild, buffer);
}

struct node* deserialize(char** ptr) {
    char* token = strtok_r(NULL, ",", ptr);
    
    if (token == NULL || strcmp(token, "#") == 0) {
        return NULL;
    }

    struct node* newNode = createNode(atoi(token));
    newNode->leftChild = deserialize(ptr);
    newNode->rightChild = deserialize(ptr);

    return newNode;
}

int main() {
    struct node* root = createNode(20);
    root->leftChild = createNode(10);
    root->rightChild = createNode(30);

    char buffer[200] = "";
    serialize(root, buffer);
    printf("String: %s\n", buffer);

    char* data_copy = strdup(buffer);
    char* ptr = data_copy;
    
    char* first_token = strtok_r(ptr, ",", &ptr);
    struct node* newRoot = createNode(atoi(first_token));
    newRoot->leftChild = deserialize(&ptr);
    newRoot->rightChild = deserialize(&ptr);

    if (newRoot != NULL) {
        printf("Reconstruit: %d\n", newRoot->data);
    }

    free(data_copy);
    return 0;
}
