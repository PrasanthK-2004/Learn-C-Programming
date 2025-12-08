#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st
{
    int roll;
    char name[20];
    float mark;
    struct st *prev;
    struct st *next;
};

struct st *head = NULL, *tail = NULL;

// Function Prototypes
void add_begin();
void add_end();
void add_position();
void del_begin();
void del_end();
void del_position();
void del_all();
void display_forward();
void display_reverse();
void reverse_node();
void reverse_data();
void save_file();
void load_file();
void sort_menu();
void sort_roll();
void sort_name();
void sort_mark();
void search_menu();
void search_roll();
void search_name();
void update_student();
int count();

// ------------------------- MAIN ----------------------------
int main()
{
    int ch;

    while (1)
    {
        printf("\n=============== STUDENT DLL MENU ===============\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Position\n");
        printf("6. Delete at End\n");
        printf("7. Display Forward\n");
        printf("8. Display Reverse\n");
        printf("9. Reverse Node Links\n");
        printf("10. Reverse Data Only\n");
        printf("11. Save to File\n");
        printf("12. Load from File\n");
        printf("13. Sort\n");
        printf("14. Search\n");
        printf("15. Update Student\n");
        printf("16. Count\n");
        printf("17. Delete All\n");
        printf("18. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: add_begin(); break;
        case 2: add_position(); break;
        case 3: add_end(); break;
        case 4: del_begin(); break;
        case 5: del_position(); break;
        case 6: del_end(); break;
        case 7: display_forward(); break;
        case 8: display_reverse(); break;
        case 9: reverse_node(); break;
        case 10: reverse_data(); break;
        case 11: save_file(); break;
        case 12: load_file(); break;
        case 13: sort_menu(); break;
        case 14: search_menu(); break;
        case 15: update_student(); break;
        case 16: printf("\nCount = %d\n", count()); break;
        case 17: del_all(); break;
        case 18: exit(0);
        default: printf("Invalid choice!\n");
        }
    }
}

// ------------------------ INSERT BEGIN -----------------------
void add_begin()
{
    struct st *temp = malloc(sizeof(struct st));
    printf("Enter roll name mark: ");
    scanf("%d %s %f", &temp->roll, temp->name, &temp->mark);

    temp->prev = NULL;
    temp->next = head;

    if (head != NULL)
        head->prev = temp;
    else
        tail = temp;

    head = temp;
}

// ------------------------- INSERT END ------------------------
void add_end()
{
    struct st *temp = malloc(sizeof(struct st));
    printf("Enter roll name mark: ");
    scanf("%d %s %f", &temp->roll, temp->name, &temp->mark);

    temp->next = NULL;
    temp->prev = tail;

    if (tail != NULL)
        tail->next = temp;
    else
        head = temp;

    tail = temp;
}

// ------------------------ INSERT POSITION --------------------
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
    if (pos == n + 1)
    {
        add_end();
        return;
    }

    struct st *temp = malloc(sizeof(struct st));
    printf("Enter roll name mark: ");
    scanf("%d %s %f", &temp->roll, temp->name, &temp->mark);

    struct st *p = head;
    while (i < pos)
    {
        p = p->next;
        i++;
    }

    temp->next = p;
    temp->prev = p->prev;
    p->prev->next = temp;
    p->prev = temp;
}

// ------------------------ DELETE BEGIN -----------------------
void del_begin()
{
    if (head == NULL)
    {
        printf("List empty!\n");
        return;
    }

    struct st *temp = head;

    head = head->next;
    if (head) head->prev = NULL;
    else tail = NULL;

    free(temp);
    printf("Deleted first node.\n");
}

// ------------------------ DELETE END -------------------------
void del_end()
{
    if (tail == NULL)
    {
        printf("List empty!\n");
        return;
    }

    struct st *temp = tail;
    tail = tail->prev;

    if (tail) tail->next = NULL;
    else head = NULL;

    free(temp);
    printf("Deleted last node.\n");
}

// ------------------------ DELETE POSITION ---------------------
void del_position()
{
    int pos, i=1, n=count();
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) { printf("Invalid\n"); return; }

    if (pos == 1) { del_begin(); return; }
    if (pos == n) { del_end(); return; }

    struct st *p = head;
    while (i < pos) { p = p->next; i++; }

    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);
    printf("Node deleted.\n");
}

// ------------------------ DISPLAY FORWARD ---------------------
void display_forward()
{
    struct st *p = head;
    if (!p) { printf("List empty!\n"); return; }

    printf("\nROLL\tNAME\tMARK\n");
    while (p)
    {
        printf("%d\t%s\t%.2f\n", p->roll, p->name, p->mark);
        p = p->next;
    }
}

// ------------------------ DISPLAY REVERSE ---------------------
void display_reverse()
{
    struct st *p = tail;
    if (!p) { printf("List empty!\n"); return; }

    printf("\nROLL\tNAME\tMARK\n");
    while (p)
    {
        printf("%d\t%s\t%.2f\n", p->roll, p->name, p->mark);
        p = p->prev;
    }
}

// ------------------------ REVERSE NODE LINKS ------------------
void reverse_node()
{
    struct st *p = head, *temp = NULL;

    while (p)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
    }

    if (temp)
        head = temp->prev;

    printf("Node links reversed.\n");
}

// ------------------------ REVERSE DATA ONLY -------------------
void reverse_data()
{
    int n = count();
    if (n <= 1) return;

    struct st *left = head;
    struct st *right = tail;

    while (left != right && left->prev != right)
    {
        // swap roll
        int r = left->roll;
        left->roll = right->roll;
        right->roll = r;

        // swap name
        char tname[20];
        strcpy(tname, left->name);
        strcpy(left->name, right->name);
        strcpy(right->name, tname);

        // swap marks
        float m = left->mark;
        left->mark = right->mark;
        right->mark = m;

        left = left->next;
        right = right->prev;
    }

    printf("Data reversed successfully.\n");
}
/*                          // ------ OR ------
void reverse_data(ST *ptr)
{
	int c=count(ptr);

	ST *p1,*p2;
	p1=ptr;
	p2=ptr;

	while(p2->next!=0)
		p2=p2->next;

	int size=sizeof(ST)-16;

	ST temp;

	for(int i=0;i<c/2;i++)
	{

		memcpy(&temp.roll,&p1->roll,size);
		memcpy(&p1->roll,&p2->roll,size);
		memcpy(&p2->roll,&temp.roll,size);

		p1=p1->next;
		p2=p2->prev;
	}


}
*/

// ----------------------- SAVE TO FILE -------------------------
void save_file()
{
    FILE *fp = fopen("student.txt", "w");
    if (!fp) { printf("Error opening file\n"); return; }

    struct st *p = head;
    while (p)
    {
        fprintf(fp, "%d %s %.2f\n", p->roll, p->name, p->mark);
        p = p->next;
    }

    fclose(fp);
    printf("Saved to student.txt\n");
}

// ----------------------- LOAD FROM FILE -----------------------
void load_file()
{
    FILE *fp = fopen("student.txt", "r");
    if (!fp) { printf("File not found!\n"); return; }

    del_all();

    struct st *temp;

    while (1)
    {
        temp = malloc(sizeof(struct st));
        if (fscanf(fp, "%d %s %f", &temp->roll, temp->name, &temp->mark) != 3)
        {
            free(temp);
            break;
        }

        temp->next = NULL;
        temp->prev = tail;

        if (!head)
            head = temp;
        else
            tail->next = temp;

        tail = temp;
    }

    fclose(fp);
    printf("Data loaded from file.\n");
}

// ----------------------- SORT MENU ----------------------------
void sort_menu()
{
    int ch;
    printf("\n1.Sort by Roll\n2.Sort by Name\n3.Sort by Marks\nEnter: ");
    scanf("%d", &ch);

    if (ch == 1) sort_roll();
    else if (ch == 2) sort_name();
    else if (ch == 3) sort_mark();
    else printf("Invalid\n");
}

// ---------------------- SORT BY ROLL --------------------------
void sort_roll()
{
    struct st *i, *j;
    struct st temp;

    for (i = head; i && i->next; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->roll > j->roll)
            {
                temp = *i;
                *i = *j;
                *j = temp;

                struct st *swap = i->next;
                i->next = j->next;
                j->next = swap;
            }

    printf("Sorted by Roll.\n");
}

// ---------------------- SORT BY NAME --------------------------
void sort_name()
{
    struct st *i, *j;
    struct st temp;

    for (i = head; i && i->next; i = i->next)
        for (j = i->next; j; j = j->next)
            if (strcmp(i->name, j->name) > 0)
            {
                temp = *i;
                *i = *j;
                *j = temp;

                struct st *swap = i->next;
                i->next = j->next;
                j->next = swap;
            }

    printf("Sorted by Name.\n");
}

// ---------------------- SORT BY MARK --------------------------
void sort_mark()
{
    struct st *i, *j;
    struct st temp;

    for (i = head; i && i->next; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->mark > j->mark)
            {
                temp = *i;
                *i = *j;
                *j = temp;

                struct st *swap = i->next;
                i->next = j->next;
                j->next = swap;
            }

    printf("Sorted by Marks.\n");
}

// ----------------------- SEARCH MENU --------------------------
void search_menu()
{
    int ch;
    printf("\n1.Search by Roll\n2.Search by Name\nEnter choice: ");
    scanf("%d", &ch);

    if (ch == 1) search_roll();
    else if (ch == 2) search_name();
    else printf("Invalid\n");
}

// ------------------------ SEARCH BY ROLL ----------------------
void search_roll()
{
    int r;
    printf("Enter roll: ");
    scanf("%d", &r);

    struct st *p = head;
    while (p)
    {
        if (p->roll == r)
        {
            printf("Found: %d %s %.2f\n", p->roll, p->name, p->mark);
            return;
        }
        p = p->next;
    }

    printf("Roll not found!\n");
}

// ------------------------ SEARCH BY NAME ----------------------
void search_name()
{
    char n[20];
    printf("Enter name: ");
    scanf("%s", n);

    struct st *p = head;
    while (p)
    {
        if (strcmp(p->name, n) == 0)
        {
            printf("Found: %d %s %.2f\n", p->roll, p->name, p->mark);
            return;
        }
        p = p->next;
    }

    printf("Name not found!\n");
}

// ------------------------- UPDATE STUDENT ----------------------
void update_student()
{
    int r;
    printf("Enter roll to update: ");
    scanf("%d", &r);

    struct st *p = head;
    while (p)
    {
        if (p->roll == r)
        {
            printf("Enter new roll name marks: ");
            scanf("%d %s %f", &p->roll, p->name, &p->mark);
            printf("Updated.\n");
            return;
        }
        p = p->next;
    }

    printf("Roll not found.\n");
}

// ----------------------------- COUNT ---------------------------
int count()
{
    int c = 0;
    struct st *p = head;

    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

// ----------------------------- DELETE ALL -----------------------
void del_all()
{
    struct st *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    tail = NULL;
    printf("All nodes deleted.\n");
}
