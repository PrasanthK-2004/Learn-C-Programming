#include <stdio.h>
#include <stdlib.h>

/* Tree node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

/* Function prototypes */
struct node* insert(struct node *, int);
struct node* delete_node(struct node *, int);
struct node* min_value_node(struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
int search(struct node *, int);
int height(struct node *);
void free_tree(struct node *);

/* ---------------- MAIN ---------------- */
int main()
{
    int choice, key;

    while (1)
    {
        printf("\n------ BINARY SEARCH TREE ------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Height of Tree\n");
        printf("8. Delete entire tree\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = delete_node(root, key);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Height = %d\n", height(root));
                break;

            case 8:
                free_tree(root);
                root = NULL;
                printf("Tree deleted\n");
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

/* -------- INSERT -------- */
struct node* insert(struct node *root, int key)
{
    if (!root)
    {
        struct node *temp = malloc(sizeof(struct node));
        temp->data = key;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

/* -------- DELETE NODE -------- */
struct node* delete_node(struct node *root, int key)
{
    if (!root) return root;

    if (key < root->data)
        root->left = delete_node(root->left, key);
    else if (key > root->data)
        root->right = delete_node(root->right, key);
    else
    {
        /* Node with one or no child */
        if (!root->left)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        /* Node with two children */
        struct node *temp = min_value_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

/* -------- FIND MIN -------- */
struct node* min_value_node(struct node *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

/* -------- SEARCH -------- */
int search(struct node *root, int key)
{
    if (!root) return 0;

    if (key == root->data)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

/* -------- TRAVERSALS -------- */
void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* -------- HEIGHT -------- */
int height(struct node *root)
{
    if (!root) return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}

/* -------- DELETE TREE -------- */
void free_tree(struct node *root)
{
    if (root)
    {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
