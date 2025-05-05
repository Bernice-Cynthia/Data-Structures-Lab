//Program to impliment character binary tree

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>    
using namespace std;

class tree
{
    struct node
    {
        char data;
        struct node* left;
        struct node* right;
    }*head;
    public:
    tree()
    {
        head=NULL;
    }
    struct node* gethead()
    {
        return head;
    }
    void preorder(struct node*);
    void inorder(struct node*);
    void postorder(struct node*);
    void insert(char);
    int search(struct node*, char, int);
};

int main()
{
    int chc;
    tree obj;
    while (1) 
    {
        printf("\nMENU\n ");
        printf("1. Insert  \n 2. Preorder \n 3. Inorder \n ");
        printf("4. Postorder  \n 5. Search \n 6. Exit \n ");
        printf("Enter your choice : ");
        scanf("%d", &chc);

        switch(chc)
        {
            case 1:
            {
                char val;
                printf("Enter the character to be inserted: ");
                cin>>val;
                obj.insert(val);
                break;
            }
            case 2:
            {
                obj.preorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 3:
            {
                obj.inorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 4:
            {
                obj.postorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 5:
            {
                char key;
                printf("Enter the character to be searched :");
                cin>>key;
                int ret = obj.search(obj.gethead(), key, 0);
                if (ret == 0)
                {
                    cout<<"The character was not found \n";
                }
                else
                {
                    cout<<"The character was found \n";
                }
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
        }
    }
    return 0;
}

void tree::insert(char data)
{
    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->data=data;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        queue<struct node*> que;
        que.push(head);
        while(!que.empty())
        {
            struct node* Node = que.front();
            que.pop();
            if (Node->left != nullptr)
            {
                que.push(Node->left);
            }
            else
            {
                Node->left=newnode;
                return;
            }
            if (Node->right != nullptr)
            {
                que.push(Node->right);
            }
            else
            {
                Node->right=newnode;
                return;
            }
        }
    }
}


void tree::inorder(struct node* root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}

void tree::preorder(struct node* root)
{
    if(root)
    {
        cout<<root->data<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
}

void tree::postorder(struct node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"  ";
    }
}

int tree::search(struct node* root, char key, int flag)
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
