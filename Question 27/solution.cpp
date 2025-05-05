//Menu-driven program to implement priority queue adt using max tree

#include <cstdio>
#include <cstdlib>
#include <iostream>
//#include <queue>    
//#include <stack>
using namespace std;

class TREE
{
    int cur;
    int tree[50];
    public:
    TREE()
    {
        cur=-1;
        for(int i = 0; i<50; i++)
        {
            tree[i]=0;
        }
    }
    void insert(int);
    bool search(int, int);
    int deletion();
    void heapify_down();
    void heapify_up();
    void display();
    int* heap_sort(int &size);
    bool isempty();
};

int main()
{
    int chc;
    TREE obj;
    while (1) 
    {
        cout<<("\nMENU \n 1. Insertion \n 2. Deletion \n 3. Display \n 4. Search \n 5. Sort(heap sort) \n 6. Exit \n");
        cout<<("Enter the choice: ");
        cin>>chc;
        switch(chc)
        {
            case 1:
            {
                int val;
                cout<<("Enter the number to be inserted: ");
                cin>>val;
                int ret;
                obj.insert(val);
                break;
            }
            case 2:
            {
                int ret=obj.deletion();
                if(ret!=-9999)
                {
                    cout<<"Deletion successful. The deleted element is "<<ret<<"\n";
                }
                break;
            }
            case 3:
            {
                obj.display();
                break;
            }
            case 4:
            {
                int key;
                cout<<"Enter the element to be searched: ";
                cin>>key;
                bool ret = obj.search(1, key);
                if (ret == false)
                {
                    cout<<"The element was not found\n";
                }
                else
                {
                    cout<<"The element was found\n";
                }
                break;
            }
            case 5:
            {
                int size;
                int* arr = obj.heap_sort(size);
                if (arr==NULL)
                {
                    break;
                }
                for(int i = 1;i<=size;i++)
                {
                    cout<<arr[i]<<"  ";
                }
                cout<<"\n";
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
            default:
            {
                cout<<"Invalid Input\n";
            }
        }
    }
}

//Function to check if tree is empty
bool TREE::isempty()
{
    if(cur==-1)
    {
        return true;
    }
    else
    {
        return false;
    }

}

//Function to Insert elements
void TREE::insert(int data)
{
    if(cur==-1)
    {
        tree[1]=data;
        cur=1;
    }
    else
    {
        cur++;
        tree[cur]=data;
        heapify_up();
    }
}

//Function to Heapify Up
void TREE::heapify_up()
{
    int i = cur;
    while(tree[i/2]<tree[i]&&i>1)
    {
        int temp = tree[i/2];
        tree[i/2] = tree[i];
        tree[i] = temp;
        i=i/2;
    }
}

//Function to Delete elements
int TREE::deletion()
{
    if(cur==-1)
    {
        cout<<"Queue is empty \n";
        return -9999;
    }
    else
    {
        int data=tree[1];
        tree[1]=tree[cur];
        cur--;
        heapify_down();
        return data;
    }
}

//Function to Heapify Down
void TREE::heapify_down()
{
    int i = 1;
    while(2*i<=cur)
    {
        int lar = i;
        int left=2*i;
        int right=2*i+1;
        if (left<=cur&&tree[left]>tree[lar])
        {
            lar=left;
        }
        if(right<=cur&&tree[right]>tree[lar])
        {
            lar=right;
        }
        if (lar!=i)
        {
            int temp=tree[i];
            tree[i]=tree[lar];
            tree[lar]=temp;
        }
        else
        {
            break;
        }
    }
    
}

//Function to Display
void TREE::display()
{
    if(cur==-1)
    {
        cout<<"Queue is empty \n";
        return;
    }
    cout<<"Priority Queue: ";
    for(int i = 1; i<=cur; i++)
    {
        cout<<tree[i]<<"  ";
    }
    cout<<"\n";
}

//Function to Search elements
bool TREE::search(int i, int key) 
{
    if (i > cur) 
    {
        return false;
    }
    if (tree[i] < key) 
    {
        return false;
    }
    if (tree[i] == key) 
    {
        return true;
    }
    int left = 2*i;
    int right = 2*i+1;

    return search(left, key) || search(right, key);
}

//Function to Sort elements (HEAP SORT)
int* TREE::heap_sort(int &size)
{
    if (cur==-1)
    {
        cout<<"Queue is empty \n";
        return NULL;
    }
    size=cur;
    int i = cur;
    int* arr = new int[cur];
    while(!(isempty()))
    {
        arr[i]=deletion();
        i--;
    }
    return arr;
}
