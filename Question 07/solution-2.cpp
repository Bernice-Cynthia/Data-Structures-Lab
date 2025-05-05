#include <cstdio>
#include <cstdlib>
#include "merge.h"

List::List() 
{
    head = NULL;
}

struct List::node* List::gethead()
{
    return head;
}

int main() 
{
    int chc;
    List obj, obj1, obj2;
    while (1) 
    {
        printf("\nMENU\n ");
        printf("1. Insertion in List1  \n 2. Insertion in List2 \n 3. Merge \n 4. Display \n 5. Exit \n ");
        printf("Enter your choice: ");
        scanf("%d", &chc);

        switch (chc) 
        {
            case 1: 
            {
                int num;
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                if (obj1.insert_list1(num)) 
                {
                    printf("Insertion was successful\n");
                } else 
                {
                    printf("Insertion was unsuccessful\n");
                }
                break;
            }
            case 2: 
            {
                int num;
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                if (obj2.insert_list2(num)) 
                {
                    printf("Insertion was successful\n");
                } else 
                {
                    printf("Insertion was unsuccessful\n");
                }
                break;
            }
            case 3:
                obj.merge_2(obj1,obj2);
                break;
            case 4:
                obj.display();
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

//Function to Insert List1
int List::insert_list1(int num)
{
    return insert(num);
}

//Function to Insert List2
int List::insert_list2(int num)
{
    return insert(num);
}

//Function to Merge 2 Lists
void List::merge_2(List& obj1, List& obj2)
{
    return merge(obj1, obj2);
}
