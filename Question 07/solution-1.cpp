//Menu driven program for List ADT using SLL to merge

#include <cstdio>
#include <cstdlib>

class List 
{
    struct node 
    {
        int data;
        struct node* next;
    } *head;

    struct node* gethead() 
    {
        return head;
    }

    public:
        List() 
        {
            head = NULL;
        }

        struct node* callgethead() 
        {
            return gethead();
        }

        int insert(int);
        void merge(List&, List&);
        void display();
};

int main() 
{
    int chc;
    List obj, obj1, obj2;
    while (1) 
    {
        printf("\nMENU\n ");
        printf("1. Insertion in Ascending  \n 2. Merge \n 3. Display \n 4. Exit \n ");
        printf("Enter your choice: ");
        scanf("%d", &chc);

        switch (chc) 
        {
            case 1: 
            {
                int num;
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                if (obj.insert(num)) 
                {
                    printf("Insertion was successful\n");
                } 
                else 
                {
                    printf("Insertion was unsuccessful\n");
                }
                break;
            }
            case 2: 
            {
                char opt;
                do 
                {
                    printf("Enter the elements of the first list: ");
                    int data;
                    scanf("%d", &data);
                    obj1.insert(data);
                    printf("To stop enter 'n' else Enter 'y': ");
                    scanf(" %c", &opt);
                } while (opt == 'y');

                do 
                {
                    printf("Enter the elements of the second list: ");
                    int data;
                    scanf("%d", &data);
                    obj2.insert(data);
                    printf("To stop enter 'n' else Enter 'y': ");
                    scanf(" %c", &opt);
                } while (opt == 'y');

                obj.merge(obj1, obj2);
                printf("Merging was successful\n");
                break;
            }
            case 3:
                obj.display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice \n");
                break;
        }
    } 
}

//Function to Insert data
int List::insert(int num) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) 
    {
        printf("Memory Allocation failed\n");
        return 0;
    }
    newnode->data = num;
    newnode->next = NULL;

    if ((head == NULL) || (head->data >= num)) 
    {
        newnode->next = head;
        head = newnode;
        return 1;
    }

    struct node* temp = head;
    while ((temp->next != NULL) && (temp->next->data < num)) 
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return 1;
}

//Function to Merge 2 Lists
void List::merge(List& obj1, List& obj2) 
{
    struct node* head1 = obj1.callgethead();
    struct node* head2 = obj2.callgethead();

    head = NULL;
    struct node** tail = &head;

    while (head1 != NULL && head2 != NULL) 
    {
        struct node** smaller = (head1->data <= head2->data) ? &head1 : &head2;
        *tail = *smaller;
        *smaller = (*smaller)->next;
        tail = &((*tail)->next);
    }

    *tail = (head1 != NULL) ? head1 : head2;
}

//Function to Display the List
void List::display() 
{
    if (head == NULL)
    {
        printf("The List is empty \n");
    } 
    else 
    {
        struct node* temp = head;
        while (temp->next != NULL) 
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

