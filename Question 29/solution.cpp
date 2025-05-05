//Menu-driven program to implement HASH ADT - QUADRATIC PROBING

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class HASH
{
    int arr[7];
    int hashfunc(int key)
    {
        return key%7;
    }
public:
    HASH()
    {
        for (int i = 0; i < 7;i++)
        {
            arr[i] = -1;
        }
    }
    bool insert(int);
    int remove(int);
    int search(int);
    void display();
};

int main()
{
    HASH obj;
    int chc, num, out;

    while (1)
    {
        cout << "\n MENU \n";
        cout << " 1. Insert \n 2. Delete \n 3. Search \n 4. Display \n 5. Exit \n";
        cout << "Enter your choice: ";
        cin >> chc;
        switch (chc)
        {
            case 1:
                cout << "Enter the number to be inserted: ";
                cin >> num;
                if (obj.insert(num))
                {
                    cout << "The number was successfully inserted";
                }
                else
                {
                    cout << "The table is full";
                }
                cout << "\n";
                break;

            case 2:
                cout << "Enter the number to be deleted: ";
                cin >> num;
                out = obj.remove(num);
                if (out > -1)
                {
                    cout << "The deleted number was found at the index " << out;
                }
                else 
                {
                    cout << "The number was not found ";
                }
                cout << "\n";
                break;

            case 3:
                cout << "Enter the number to be searched: ";
                cin >> num;
                out = obj.search(num);
                if (out > -1)
                {
                    cout << "The number was found at the index " << out;
                }
                else 
                {
                    cout << "The number was not found ";
                }
                cout << "\n";
                break;

            case 4:
                obj.display();
                break;

            case 5:
                exit(0);

            default:
                cout << "Invalid Choice \n";
        }
    }
    return 0;
}

// Function to Insert keys
bool HASH::insert(int num)
{
    int ret = hashfunc(num);
    if (arr[ret] == -1)
    {
        arr[ret] = num;
        return true;
    }
    int temp = ret;
    bool flag = false;
    int i = 0;
    while (!flag)
    {
        i++;
        ret = hashfunc(num + i + i*i);
        if (arr[ret] == -1)
        {
            arr[ret] = num;
            flag =  true;
        }
        if (ret == temp)
        {
            break;
        }
    }
    return flag;
}

// Function to Remove keys
int HASH::remove(int num)
{
    int ret = search(num);
    if (ret > -1)
    {
        arr[ret] = -99;
        return ret;
    }
    return -999;
}

// Function to Search keys
int HASH::search(int num)
{
    for (int i = 0; i < 7;i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -999;
}

// Function to display the keys
void HASH::display()
{
    for (int i = 0; i < 7;i++)
    {
        cout <<  arr[i] << "  ";
    }
    cout << "\n";
}
