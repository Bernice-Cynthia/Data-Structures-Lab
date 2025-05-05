//binary expression tree
#include <cstdio>
#include <cstdlib>
#include "bintreeheader.h"

TREE::TREE()
{
    head=NULL;
}

string postfix();
void consttree(string, TREE&);

int main()
{
    string post;
    int chc;
    TREE obj;
    while (1) 
    {
        printf("\nMENU\n ");
        printf("1. Insert Postfix Expression \n 2. Construction of Tree \n 3. Inorder \n 4. Preorder \n 5. Postorder \n 6. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &chc);

        switch(chc)
        {
            case 1:
            {
                post=postfix();
                break;
            }
            case 2:
            {
                consttree(post, obj);
                break;
            }
            case 3:
            {
                obj.inorder(obj.gethead());
                printf("\n");
                break;
            }
            case 4:
            {
                obj.preorder(obj.gethead());
                printf("\n");
                break;
            }
            case 5:
            {
                obj.postorder(obj.gethead());
                printf("\n");
                break;
            }
            case 6:
            {
                exit(0);
            }
            default:
            {
                printf("Invalid Choice \n");
            }
        }
    }
    return 0;
}

string postfix()
{
    string post;
    cout<<"Enter a valid postfix expression: ";
    cin>>post;
    return post;
}

void consttree(string post, TREE& obj)
{
    obj.sethead(obj.exptree(post, NULL, '\0'));
}
