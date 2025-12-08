#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st
{
    int roll;
    char name[20];
    float mark;
    struct st *next;
};

struct st *head = NULL;

/* Function prototypes */
void add_begin();
void add_position();
void add_end();
void del_begin();
void del_position();
void del_end();
void display();
void reverse_node();
void save_file();
int count();
void del_all();

/* ---------------- MAIN ---------------- */
int main()
{
    int choice;

    while (1)
    {
        printf("\n----- CIRCULAR LINKED LIST MENU -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at any position\n");
        printf("3. Insert at end\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at any position\n");
        printf("6. Delete at end\n");
        printf("7. Display\n");
        printf("8. Reverse nodes\n");
        printf("9. Save to file\n");
        printf("10. Count nodes\n");
        printf("11. Delete all\n");
        printf("12. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: add_begin(); break;
            case 2: add_position(); break;
            case 3: add_end(); break;
            case 4: del_begin(); break;
            case 5: del_position(); break;
            case 6: del_end(); break;
            case 7: display(); break;
            case 8: reverse_node(); break;
            case 9: save_file(); break;
            case 10: printf("Count = %d\n", count()); break;
            case 11: del_all(); break;
            case 12: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

/* -------- INSERT AT BEGIN -------- */
void add_begin()
{
    struct st *temp = malloc(sizeof(struct st));
    printf("Enter roll name marks: ");
    scanf("%d %s %f", &temp->roll, temp->name, &temp->mark);

    if (!head)
    {
        head = temp;
        temp->next = head;
        return;
    }

    struct st *p = head;
    while (p->next != head)
        p = p->next;

    temp->next = head;
    p->next = temp;
    head = temp;
}

/* -------- INSERT AT END -------- */
void add_end()
{
    struct st *temp = malloc(sizeof(struct st));
    printf("Enter roll name marks: ");
    scanf("%d %s %f", &temp->roll, temp->name, &temp->mark);

    if (!head)
    {
        head = temp;
        temp->next = head;
        return;
    }

    struct st *p = head;
    while (p->next != head)
        p = p->next;

    p->next = temp;
    temp->next = head;
}

/* -------- INSERT AT POSITION -------- */
void add_position()
{
    int pos, i = 1, n = count();
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        add_begin();
        return;
    }

    struct st *temp = malloc(sizeof(struct st));
    printf("Enter roll name marks: ");
    scanf("%d %s %f", &temp->roll, temp->name, &temp->mark);

    struct st *p = head;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
    }

    temp->next = p->next;
    p->next = temp;
}

/* -------- DELETE BEGIN -------- */
void del_begin()
{
    if (!head)
    {
        printf("List empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct st *p = head;
    while (p->next != head)
        p = p->next;

    struct st *temp = head;
    head = head->next;
    p->next = head;
    free(temp);
}

/* -------- DELETE END -------- */
void del_end()
{
    if (!head)
    {
        printf("List empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct st *p = head;
    while (p->next->next != head)
        p = p->next;

    free(p->next);
    p->next = head;
}

/* -------- DELETE POSITION -------- */
void del_position()
{
    int pos, i = 1, n = count();
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        del_begin();
        return;
    }

    struct st *p = head;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
    }

    struct st *q = p->next;
    p->next = q->next;
    free(q);
}

/* -------- DISPLAY -------- */
void display()
{
    if (!head)
    {
        printf("List empty\n");
        return;
    }

    struct st *temp = head;
    printf("\nRoll\tName\tMarks\n");
    printf("-----------------------\n");

    do
    {
        printf("%d\t%s\t%.2f\n",
               temp->roll, temp->name, temp->mark);
        temp = temp->next;
    } while (temp != head);
}

/* -------- REVERSE NODE -------- */
void reverse_node()
{
    if (!head || head->next == head)
        return;

    struct st *prev = head;
    struct st *curr = head->next;
    struct st *next;

    while (curr != head)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    curr->next = prev;
    head = prev;

    printf("List reversed successfully\n");
}

/* -------- SAVE FILE -------- */
void save_file()
{
    FILE *fp = fopen("student.txt", "w");
    if (!fp)
    {
        printf("File error\n");
        return;
    }

    if (head)
    {
        struct st *p = head;
        do
        {
            fprintf(fp, "%d %s %.2f\n",
                    p->roll, p->name, p->mark);
            p = p->next;
        } while (p != head);
    }

    fclose(fp);
    printf("Saved to student.txt\n");
}

/* -------- COUNT -------- */
int count()
{
    if (!head) return 0;

    int c = 0;
    struct st *p = head;
    do
    {
        c++;
        p = p->next;
    } while (p != head);

    return c;
}

/* -------- DELETE ALL -------- */
void del_all()
{
    if (!head)
        return;

    struct st *p = head->next;
    while (p != head)
    {
        struct st *temp = p;
        p = p->next;
        free(temp);
    }

    free(head);
    head = NULL;
    printf("All nodes deleted\n");
}
