#include <stdio.h>

#define MAX_SIZE 10
typedef struct stack
{
    int arr[MAX_SIZE];
    int top;

} Stack;

void initializeStack(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *stack);
void printStack(Stack *stack);

void main()
{
    Stack stack;
    initializeStack(&stack);
    pop(&stack);
    push(&stack, 10);
    push(&stack, 15);
    push(&stack, 16);
    push(&stack, 12);
    push(&stack, 1);
    push(&stack, 5);
    push(&stack, 25);
    push(&stack, 90);
    push(&stack, 17);
    pop(&stack);
    push(&stack, 8);
    push(&stack, 9);
    push(&stack, 9);
    printStack(&stack);
}

void initializeStack(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int data)
{

    if (isFull(stack))
    {
        printf("Stack is Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void printStack(Stack *stack)
{

    if (isEmpty(stack))
    {
        printf("Stack is Empty");
        return;
    }

    for (int i = stack->top; i >= 0; i--)
    {

        printf("%d\t", stack->arr[i]);
    }
    printf("\n");
}
