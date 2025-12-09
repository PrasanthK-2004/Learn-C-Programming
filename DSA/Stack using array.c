#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;

void push();
void pop();
void peek();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\n------ STACK MENU ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top element)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

void push()
{
    int item;
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter element to push: ");
    scanf("%d", &item);

    stack[++top] = item;
    printf("Pushed %d\n", item);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void peek()
{
    if (top == -1)
    {
        printf("Stack empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}
