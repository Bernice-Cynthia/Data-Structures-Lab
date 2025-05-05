// Menu-driven program to implement HASH ADT - SEPARATE CHAIN

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

class HASH
{
    node** hash = new node*[7];
    int hashfunc(int key)
    {
        return key%7;
    }
    public:
    HASH()
    {
        for (int i = 0; i<7 ;i++)
        {
            hash[i]=NULL;
        }
    }
    void insert(int);
    int deletion(int);
    int search(int);
};

int main()
{
    int chc, num, ret;
    HASH obj;
    while(1)
    {
        cout << "\n MENU \n 1. Insert \n 2. Delete \n 3. Search \n 4. Exit \n";
        cout << "Enter your choice: ";
        cin >> chc;
        switch(chc)
        {
            case 1:
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                obj.insert(num);
                cout<<"Insertion was successful\n";
                break;

            case 2:
                cout<<"Enter the value to be deleted: ";
                cin>>num;
                ret = obj.deletion(num);
                if(ret==0)
                {
                    cout<<"Deletion was unsuccessful\n";
                }
                else if(ret==-1)
                {
                    cout<<"Deletion was unsuccessful. Element to be deleted was not found\n";
                }
                else
                {
                    cout<<"Deletion was successful\n";
                }
                break;

            case 3:
                cout<<"Enter the value to be searched: ";
                cin>>num;
                ret = obj.search(num);
                if(ret==-1)
                {
                    cout<<"Element was not found\n";
                }
                else
                {
                    cout<<"Element was found at position: "<<ret<<"\n";
                }
                break;

            case 4:
                exit(0);

            default:
                cout<<"Invalid Choice \n";
                break;
        }
    }
    return 0;
}

// Function to Insert
void HASH::insert(int num)
{
    int pos = hashfunc(num);
    node* newnode = new node;
    newnode->data=num;
    newnode->next=hash[pos];
    
    hash[pos]=newnode;
}

// Function to Delete
int HASH::deletion(int num)
{
    int pos = hashfunc(num);
    if(hash[pos]==NULL)
    {
        return 0;
    }
    else
    {
        node* cur = hash[pos];
        node* prev = NULL;
        while(cur)
        {
            if(cur->data==num)
            {
                if(prev)
                {
                    prev->next=cur->next;
                }
                else
                {
                    hash[pos]=cur->next;
                }
                return 1;
            }
            prev=cur;
            cur=cur->next;
        } 
    }
    return -1;
}

// Function to Search
int HASH::search(int num)
{
    int pos = hashfunc(num);
    if (hash[pos]==NULL)
    {
        return -1;
    }
    else
    {
        node* cur  = hash[pos];
        while(cur)
        {
            if(cur->data==num)
            {
                return pos;
            }
            cur=cur->next;
        }
    }
    return -1;
}

