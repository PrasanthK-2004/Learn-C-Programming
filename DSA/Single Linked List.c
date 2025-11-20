#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st {
    int roll;
    char name[20];
    float mark;
    struct st *next;
};

struct st *head = NULL;

// Function Prototypes
void add_begin();
void add_position();
void add_end();
void del_begin();
void del_position();
void del_end();
void display();
void reverse_print(struct st *);
void reverse_data();
void reverse_node();
void save_file();
int count();
void del_all();

// ---------------- MAIN ------------------
int main() {
    int choice,c;

    while(1) {
        printf("\n1.Insert at beginning\n");
        printf("2.Insert at any position\n");
        printf("3.Insert at end\n");
        printf("4.Delete at beginning\n");
        printf("5.Delete at any position\n");
        printf("6.Delete at end\n");
        printf("7.Display\n");
        printf("8.Reverse print\n");
        printf("9.Reverse data\n");
        printf("10.Reverse node\n");
        printf("11.Save file\n");
        printf("12.Count data\n");
        printf("13.Delete all\n");
        printf("14.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: add_begin(); break;
            case 2: add_position(); break;
            case 3: add_end(); break;
            case 4: del_begin(); break;
            case 5: del_position(); break;
            case 6: del_end(); break;
            case 7: display(); break;
            case 8: printf("\nReversed List:\n"); reverse_print(head); break;
            case 9: reverse_data(); break;
            case 10: reverse_node(); break;
            case 11: save_file(); break;
            case 12: c = count(); printf("\nCount: %d\n",c); break;
            case 13: del_all(); break;
            case 14: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}

// -------- INSERT AT BEGIN ----------
void add_begin() {
    struct st *temp = malloc(sizeof(struct st));
    printf("Enter roll name marks: ");
    scanf("%d%s%f", &temp->roll, temp->name, &temp->mark);
    temp->next = head;
    head = temp;
}

// ------- INSERT AT POSITION ----------
void add_position() {
    int pos, i=1, n = count();
    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > n+1) 
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1) 
    { 
    	add_begin(); 
	return; 
    }

    struct st *temp = malloc(sizeof(struct st));
    printf("Enter roll name marks: ");
    scanf("%d%s%f", &temp->roll, temp->name, &temp->mark);

    struct st *p = head;
    while(i < pos-1) 
    { 
    	p = p->next; 
	i++; 
    }

    temp->next = p->next;
    p->next = temp;
}

// -------- INSERT AT END ---------
void add_end() {
    struct st *temp = malloc(sizeof(struct st));
    printf("Enter roll name marks: ");
    scanf("%d%s%f", &temp->roll, temp->name, &temp->mark);
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
        return;
    }

    struct st *p = head;
    while(p->next) p = p->next;
    p->next = temp;
}

// ---------- DELETE BEGIN ---------
void del_begin() {
    if(head == NULL) 
    {
        printf("List empty!\n");
        return;
    }
    struct st *temp = head;
    head = temp->next;
    free(temp);
    printf("Deleted first node.\n");
}

// -------- DELETE POSITION ---------
void del_position() 
{
    int pos, i=1, n=count();
    printf("Enter position to delete: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > n) 
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1) 
    { 
    	del_begin(); 
	return; 
    }

    struct st *p = head, *q;
    while(i < pos-1) 
    { 
    	p = p->next; 
	i++; 
    }

    q = p->next;
    p->next = q->next;
    free(q);
    printf("Node deleted.\n");
}

// -------- DELETE END ---------
void del_end() {
    if(head == NULL) 
    {
    	printf("List empty\n"); 
	return; 
    }

    if(head->next == NULL) 
    {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }

    struct st *p = head, *q;
    while(p->next->next != NULL) 
    	p = p->next;

    q = p->next;
    p->next = NULL;
    free(q);
    printf("Last node deleted\n");
}

// ------- DISPLAY --------
void display() 
{
    struct st *temp = head;
    if(!temp) 
    { 
    	printf("List Empty\n"); 
	return; 
    }

    printf("\nStudent List:\n");
    while(temp) 
    {
        printf("%d\t%s\t%.2f\n", temp->roll, temp->name, temp->mark);
        temp = temp->next;
    }
}

// ------- REVERSE PRINT --------
void reverse_print(struct st *temp) 
{
    if(temp == NULL) 
    	return;
    reverse_print(temp->next);
    printf("%d\t%s\t%.2f\n", temp->roll, temp->name, temp->mark);
}

// -------- REVERSE DATA ONLY ----------
void reverse_data() 
{
    int n = count();
    struct st *arr[n];
    struct st *p = head;

    for(int i=0;i<n;i++) 
    {
    	arr[i] = p;
	p = p->next; 
    }

    for(int i=0, j=n-1; i<j; i++, j--) 
    {
        // swap roll, name, mark
        struct st temp = *arr[i];
        arr[i]->roll = arr[j]->roll;
        arr[i]->mark = arr[j]->mark;
        strcpy(arr[i]->name, arr[j]->name);

        arr[j]->roll = temp.roll;
        arr[j]->mark = temp.mark;
        strcpy(arr[j]->name, temp.name);
    }
}

// -------- REVERSE NODE LINKS ----------
void reverse_node() 
{
    struct st *prev=NULL, *curr=head, *next;

    while(curr) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("Linked list nodes reversed.\n");
}

// ---------- SAVE TO FILE ----------
void save_file()
{
    FILE *fp = fopen("student.txt","w");
    if(fp == NULL) 
    {
        printf("Error creating file\n");
        return;
    }

    struct st *p = head;
    while(p) 
    {
        fprintf(fp,"%d %s %.2f\n", p->roll, p->name, p->mark);
        p = p->next;
    }
    fclose(fp);
    printf("Saved to student.txt\n");
}

// -------- COUNT --------
int count() 
{
    int c=0;
    struct st *temp = head;
    while(temp) 
    { 
    	c++; 
	temp=temp->next;
    }
    return c;
}

// -------- DELETE ALL --------
void del_all() 
{
    struct st *temp;
    while(head) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All nodes deleted.\n");
}
