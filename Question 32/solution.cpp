//Menu-driven Program to implement GRAPH ADT using ADJACENCY LIST

#include <iostream>
#include <list>
using namespace std;

class Graph 
{
    private:
        int V;                     
        list<int>* adj;            

    public:
        Graph(int vertices) 
        {
            V = vertices;
            adj = new list<int>[V]; 
        }
        bool isvalid(int);
        bool insert(int,int);
        bool deletion(int,int);
        int search(int,int);
        void display();
        ~Graph()
        {
            delete[]adj;
        }
};

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    Graph obj(n);
    int u,v,chc;

    while (1)
    {
        cout << "\nMENU: \n";
        cout << " 1. Insert Edge \n 2. Delete Edge \n 3. Search \n 4. Display \n 5. Exit \n";
        cout << "Enter your choice: ";
        cin >> chc;
  
        switch(chc)
        {           
            case 1:
                cout << "Enter the u vertice to insert an edge: ";
                cin >> u;
                cout << "Enter the v vertice to insert an edge: ";
                cin >> v;
                if (obj.insert(u,v))
                {
                    cout << "Edge inserted between " << u << " and " << v;
                }
                else
                {
                    cout << "Invalid vertex number";
                }
                break;

            case 2:
                cout << "Enter the u vertice to delete an edge: ";
                cin >> u;
                cout << "Enter the v vertice to delete an edge: ";
                cin >> v;
                if (obj.deletion(u,v))
                {
                    cout << "Edge deleted between " << u << " and " << v;
                }
                else
                {
                    cout << "Invalid vertex number";
                }
                break;

            case 3:
                int out;
                cout << "Enter the u vertice to search an edge: ";
                cin >> u;
                cout << "Enter the v vertice to search an edge: ";
                cin >> v;
                out = obj.search(u,v);
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
                    cout << "Edge exists.";
                }
                break;

            case 4:
                obj.display();
                break;

            case 5:
                return 0;
                break;

            default:
                cout << "Invalid choice";
        }
        cout << "\n";
    }
    return 0;
}

bool Graph:: isvalid(int v) 
{
    return (v >= 0 && v < V);
}

//Function to INSERT an edge
bool Graph::insert(int u,int v)
{
    if(isvalid(u) && isvalid(v) && search(u,v) != 1)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
        return true;
    }
    return false;
}

//Function to DELETE an edge
bool Graph::deletion(int u,int v)
{
    if(isvalid(u) && isvalid(v))
    {
        adj[u].remove(v);
        adj[v].remove(u);
        return true;
    }
    return false;
}

//Function to SEARCH an edge
int Graph::search(int u,int v)
{
    if(isvalid(u) && isvalid(v))
    {
        bool found=false;
        for(int val:adj[u])
        {
            if(val==v)
            {
                found=true;
                break;
            }
        }

        if (found)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    return -999;
}

//Function to DISPLAY
void Graph::display()
{
    cout << "ADJACENCY LIST: \n";

    for(int i=0; i<V; i++)
    {
        cout << i << ": ";
        for(int x:adj[i])
        {
            cout << x << " -> ";
        }
        cout << "NULL \n";
    }
}
