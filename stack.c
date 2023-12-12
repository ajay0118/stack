#include <stdio.h>

#define MAX_SIZE 10

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        s->arr[++s->top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1; // Return an error value
    } else {
        return s->arr[s->top--];
    }
}

int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1; // Return an error value
    } else {
        return s->arr[s->top];
    }
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; ++i) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    int choice, value;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Peeked value: %d\n", value);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

