#include <stdio.h>
#include <stdlib.h>

/* Stack node structure */
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

/* Function prototypes */
void push();
void pop();
void peek();
void display();
void del_all();

/* ---------------- MAIN ---------------- */
int main()
{
    int choice;

    while (1)
    {
        printf("\n------ STACK USING LINKED LIST ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top)\n");
        printf("4. Display\n");
        printf("5. Delete all\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: del_all(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

/* -------- PUSH -------- */
void push()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter element to push: ");
    scanf("%d", &temp->data);

    temp->next = top;
    top = temp;

    printf("Pushed %d\n", temp->data);
}

/* -------- POP -------- */
void pop()
{
    if (!top)
    {
        printf("Stack Underflow\n");
        return;
    }

    struct node *temp = top;
    printf("Popped element: %d\n", temp->data);

    top = temp->next;
    free(temp);
}

/* -------- PEEK -------- */
void peek()
{
    if (!top)
    {
        printf("Stack empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

/* -------- DISPLAY -------- */
void display()
{
    if (!top)
    {
        printf("Stack empty\n");
        return;
    }

    struct node *p = top;
    printf("Stack elements (Top → Bottom):\n");

    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

/* -------- DELETE ALL -------- */
void del_all()
{
    struct node *temp;
    while (top)
    {
        temp = top;
        top = top->next;
        free(temp);
    }
    printf("All stack elements deleted\n");
}
