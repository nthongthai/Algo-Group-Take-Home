#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "implement-stack.h"

void test_stack_creation(void) {
    printf("Testing stack creation...\n");
    Node* stack = createstack(1);
    assert(peek(stack) == 1 && "Expected top element to be 1.");
    assert(size(stack) == 1 && "Expected stack size to be 1.");
    free(stack);
    printf("Stack creation test passed.\n");
}

void test_push(void) {
    printf("Testing push...\n");
    Node* stack = createstack(1);
    push(stack, 10);
    push(stack, 100);
    assert(peek(stack) == 100 && "Expected top element to be 100.");
    assert(size(stack) == 3 && "Expected stack size to be 3");
    printf("Push elements test passed.\n");
    while (size(stack) > 1) {
        pop(stack);
    }
    free(stack);
}

void test_pop(void) {
    printf("Testing pop...\n");
    Node* stack = createstack(1);
    push(stack, 5);
    int popped_data = pop(stack);
    assert(popped_data == 5 && "Expected popped value to be 5.");
    assert(size(stack) == 1 && "Expected stack size to be 1 after pop.");
    free(stack);
    printf("Pop elements test passed.\n");
}

int main (void) {
    test_stack_creation();
    test_push();
    test_pop();
    printf("All tests passed.");
    return 0;
}
