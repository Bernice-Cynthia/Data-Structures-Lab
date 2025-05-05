//Menu driven Program to implement Binary Search Tree using linked list

#include <cstdio>
#include <cstdlib>

class TREE
{
    struct node 
    {
        int data;
        struct node* left;
        struct node* right;
    };
    struct node *head;
    public:
        TREE()
        {
            head = NULL;
        }
        struct node* gethead()
        {
            return head;
        }
        void sethead(struct node* n)
        {
            head = n;
        }
        struct node* insert(int, struct node*);
        void preorder(struct node*);
        void inorder(struct node*);
        void postorder(struct node*);
        int search(struct node*, int, int);
};

int main()
{
    TREE obj;
    int chc, num, ret;
    while(1)
    {
        printf("\nMENU\n ");
        printf("1. Insert  \n 2. Preorder \n 3. Inorder \n 4. Postorder \n 5. Search \n 6. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &chc);

        switch (chc)
        {
            case 1:
                printf("Enter the number to be Inserted: ");
                scanf("%d", &num);
                obj.sethead(obj.insert(num, obj.gethead()));
                break;
            case 2:
                obj.preorder(obj.gethead());
                break;
            case 3:
                obj.inorder(obj.gethead());
                break;
            case 4:
                obj.postorder(obj.gethead());
                break;
            case 5:
                printf("Enter the number to be Searched: ");
                scanf("%d", &num);
                ret = obj.search(obj.gethead(), num, 0);
                if (ret == 0)
                {
                    printf("The character was not found \n");
                }
                else
                {
                    printf("The character was found \n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

//Function to Inser
TREE::node* TREE::insert(int num, struct node *root)
{
    if (root == NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
        return root;
    }

    if (num < root->data)
    {
        root->left = insert(num, root->left);
    }
    else 
    {
        root->right = insert(num, root->right);
    }
    return root;
}

//Function for Preorder
void TREE::preorder(struct node* root)
{
    if (head == NULL)
    {
        printf("Tree is empty \n");
        return;
    }

    if (root == NULL)
    {
        return;
    }

    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
}

//Function for Inorder
void TREE::inorder(struct node* root)
{
    if (head == NULL)
    {
        printf("Tree is empty \n");
        return;
    }

    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}

//Function for Postorder
void TREE::postorder(struct node* root)
{
    if (head == NULL)
    {
        printf("Tree is empty \n");
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
}

//Function for Search
int TREE::search(struct node* root, int key, int flag)
{
    if (root)
    {
        flag=search(root->left, key, flag);
        if (root->data==key)
        {
            flag++;
        }
        flag=search(root->right, key, flag);
    }
    return flag;
}
