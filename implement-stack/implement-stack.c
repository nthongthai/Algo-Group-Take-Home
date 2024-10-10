// OPTION 2 - IMPLEMENT STACK
// DO NOT SHARE

#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "implement-stack.h"

// 2. Implement a growable integer stack (without using container libraries like vector, list, etc.) 
//    that satisfies the following requirements:

// `push` adds a given value to the top
// `pop`  returns and removes the value at the top
// `peek` returns the value at the top
// `size` returns the count of values

Node* createstack(int num) {
    Node* current_node = (Node*)malloc(sizeof(Node));
    current_node->up = NULL;
    current_node->data = num;
    current_node->down = NULL;
    return current_node;
}

Node* head (Node* current_node) {
    if (current_node == NULL) {
        return NULL;
    }
    if (current_node->up == NULL){
        return current_node;
    } else {
        return head(current_node->up);
    }
}

void push (Node* current_node, int num) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* top_node = head(current_node);
    top_node->up = new_node;
    new_node->down = top_node;
    new_node->data = num;
    new_node->up = NULL;
}

int peek (Node* current_node) {
    Node* top_node = head(current_node);
    if (top_node != NULL) {
        return top_node->data;
    } else {
        return -1;
    }
}

int pop (Node* current_node) {
    Node* top_node = head(current_node);
    if (top_node == NULL) {
        return -1;
    }
    int val = top_node->data;
    top_node->down->up = NULL;
    free(top_node);
    return val;
}

int count (Node* current_node) {
    if (current_node == NULL) {
        return 0;
    }
    else if (current_node->down == NULL) {
        return 1;
    }
    else {
        return 1 + count(current_node->down);
    }
}

int size (Node* current_node) {
    Node* top_node = head(current_node);;
    return count(top_node);
}
