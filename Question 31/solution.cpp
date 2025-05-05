//Menu-driven Program to implement GRAPH ADT using ADJACENCY MATRIX

#include <iostream>
using namespace std;
#define max 10

class Graph
{
    int mat[max][max];
    int v;
    public:
        Graph()
        {
            v = 0;
            for(int i = 0; i < max; i++)
            {
                for(int j = 0; j < max; j ++)
                {
                    mat[i][j] = 0;
                }
            }
        }
        int AddV();
        bool AddE(int,int,int);
        bool DelE(int,int);
        int SearchE(int,int);
        void Display();
};

int main()
{
    Graph obj;
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int chc, a, b, out;
    for (int i = 0; i < n; i++)
    {
        out = obj.AddV();
    }

    while(1)
    {
        cout << "\nMENU: \n";
        cout << " 1. Insert Edge \n 2. Delete Edge \n 3. Search \n 4. Display \n 5. Exit \n";
        cout << "Enter your choice: ";
        cin >> chc;
        out = 0;

        switch(chc)
        {
            case 1:
                cout << "Enter the vertex a : ";
                cin >> a;
                cout << "Enter the vertex b: ";
                cin >> b;
                cout << "Enter the weight: ";
                cin >> out;
                if (obj.AddE(a,b,out))
                {
                    cout << "Edge has been added.";
                }
                else 
                {
                    cout << "Invalid vertices.";
                }
                break;

            case 2:
                cout << "Enter the vertex a : ";
                cin >> a;
                cout << "Enter the vertex b: ";
                cin >> b;
                if (obj.DelE(a,b))
                {
                    cout << "Edge has been deleted.";
                }
                else 
                {
                    cout << "No edges to delete.";
                }
                break;

            case 3:
                cout << "Enter the vertex a : ";
                cin >> a;
                cout << "Enter the vertex b: ";
                cin >> b;
                out = obj.SearchE(a,b);
                if (out == 0)
                {
                    cout << "No edge exists.";
                }
                else if (out < 0)
                {
                    cout << "Invalid vertices.";
                }
                else 
                {
                    cout << "The edge is " << out;
                }
                break;

            case 4:
                obj.Display();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice. \n";
        }
        cout << "\n";
    }
    return 0;
}

// Function to ADD a VERTEX
int Graph::AddV()
{
    if(v > max)
    {
        return -99;
    }

    return v++;
}

// Function to ADD a EDGE
bool Graph::AddE(int a, int b, int out)
{
    if(a < 0 || b < 0 || a >= v || b >= v)
    {
        return false;
    }

    mat[a][b] = mat[b][a] = out;
    return true;
}

// Function to DELETE a EDGE
bool Graph::DelE(int a, int b)
{
    if(a < 0 || b < 0 || a >= v || b >= v || mat[a][b] == 0)
    {
        return false;
    }

    mat[a][b] = mat[b][a] = 0;
    return true;
}

// Function to SEARCH a VERTEDGEEX
int Graph :: SearchE(int a, int b)
{
    if(a < 0 || b < 0 || a >= v || b >= v)
    {
        return -99;
    }

    return mat[a][b];
}

// Function to DISPLAY
void Graph :: Display()
{
    cout << "ADJACENCY MATRIX: \n";

    if (v==0)
    {
        cout << "NULL\n";
        return;
    }

    cout << "X   ";
    for(int i = 0; i < v; i ++)
    {
        cout << i << "  ";
    }
    cout << "\n";

    for(int i = 0; i < v; i ++)
    {
        cout << i <<":  ";
        for(int j = 0; j < v; j++)
        {
            cout << mat[i][j] << "  ";
        }
        cout << "\n";
    }
}


