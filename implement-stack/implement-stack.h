#ifndef IMPLEMENT_STACK_H
#define IMPLEMENT_STACK_H

typedef struct Node {
    int data;
    struct Node* up;
    struct Node* down;
} Node;

Node* createstack(int num);
void push(Node* current_node, int num);
int peek(Node* current_node);
int pop(Node* current_node);
int size(Node* current_node);

#endif
