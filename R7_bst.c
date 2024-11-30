#include <stdio.h>
#include <stdlib.h>

// Node structure for a BST
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function prototypes
struct node *insert(struct node *root, int data);
struct node *search(struct node *root, int data);
struct node *delete(struct node *root, int data);
void display(struct node *root);

void main()
{
    struct node *root = NULL; // Initialize an empty BST
    int op, data;

    do
    {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("------------------------------------\n");
        printf("Your choice: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter data to search: ");
            scanf("%d", &data);
            if (search(root, data))
                printf("Item found\n");
            else
                printf("Item not found\n");
            break;
        case 3:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = delete (root, data);
            break;
        case 4:
            printf("Tree traversal: ");
            display(root);
            printf("\n");
            break;
        case 5:
            exit(0); 
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}

// Function to insert a new node
struct node *insert(struct node *root, int data)
{
    struct node *t, *t1 = root;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->left = t->right = NULL;
    
    if (root == NULL)
        root = t;
    else
    {
        while (t1 != NULL && t1->data != data)
        {
            if (data < t1->data)
            {
                if (t1->left == NULL)// If left child is null, insert here
                { 
                    t1->left = t;
                    break;
                }
                t1 = t1->left; // Move to left subtree
            }
            else
            { 
                if (t1->right == NULL)// If right child is null, insert here
                { 
                    t1->right = t;
                    break;
                }
                t1 = t1->right; // Move to right subtree
            }
        }
        
        if (t1 != NULL && t1->data == data) // Check for duplicates 
        {
            printf("Duplicate element not allowed\n");
            free(t);
        }
    }

    return root;
}

struct node *search(struct node *root, int data)
{
    while (root != NULL && root->data != data) 
    {
        if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// Function to delete a node in the BST 
struct node *delete(struct node *root, int data)
{
    struct node *t1 = root, *t2 = NULL; 
    while (t1 != NULL && t1->data != data)
    {
        t2 = t1;
        if (data < t1->data)
            t1 = t1->left;
        else
            t1 = t1->right;
    }

    if (t1 == NULL)
    {
        printf("Node not found\n");
        return root;
    }

    if (t1->left == NULL && t1->right == NULL) // Case1: Node  has no children
    {
        if (t2 == NULL)   
            root = NULL; 
        else
            if (t2->left == t1)  
                t2->left = NULL; 
            else
                t2->right = NULL; 
        free(t1); 
    }

    else if (t1->left == NULL || t1->right == NULL) // Case 2: Node has one child
    {                                                                   
        struct node *child = (t1->left != NULL) ? t1->left : t1->right; // Determine which child exists

        if (t2 == NULL)          
            root = child;       
        else if (t2->left == t1) 
            t2->left = child;    
        else
            t2->right = child; // Replace t1 with its child

        free(t1); 
    }
    
    else // Case 3: Node has two children
    {
        struct node *sucpar = t1;
        struct node *t2 = t1->right;
        while (t2->left != NULL)
        {
            sucpar = t2;
            t2 = t2->left;
        }
        t1->data = t2->data;
        if (sucpar->left == t2)
            sucpar->left = t2->right;
        else
            sucpar->right = t2->right;
        free(t2);
    }

    return root;
}

// Function to display the BST
void display(struct node *root)
{
    if (root != NULL)
    {
        display(root->left); 
        printf("%d ", root->data);
        display(root->right);
    }
}
