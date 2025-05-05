//Program to implement ALGORITHMS 

#include <iostream>
#include <queue>
#include <utility>
#include <cstdlib>
using namespace std;

class ALGORITHM 
{
    int n;
    int visited[100];
    int graph[100][100];

public:
    ALGORITHM(int v) 
    {
        n = v;
        for (int i = 0; i < n; i++)
            visited[i] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = 0;
    }

    bool isvalid(int);
    void insert(int, int, int);
    void prims();
    void kruskal();
    void dijikstra();
};

int main() 
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    ALGORITHM obj(n);
    for (int i = 0; i < n; i++) 
    {
        int val;
        cout << "Enter the number of vertices vertex " << (i + 1) << " is connected to: ";
        cin >> val;
        for (int j = 0; j < val; j++) 
        {
            cout << "Enter the vertex it is connected to and its weight: ";
            int v, w;
            cin >> v >> w;
            obj.insert(i, v - 1, w);
        }
    }
    int chc;
    while (1) 
    {
        cout << "\n MENU \n";
        cout << " 1. Prim's Algorithm \n 2. Kruskal's Algorithm \n 3. Dijkstra's Algorithm \n 4. to Exit\n";
        cout << "Enter your choice: ";
        cin >> chc;
        switch (chc) 
        {
            case 1:
                obj.prims();
                break;
            case 2:
                obj.kruskal();
                break;
            case 3:
                obj.dijikstra();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid input ";
        }
    } 
    return 0;
}

// Function to check if vertex is valid
bool ALGORITHM::isvalid(int v) 
{
    return (v >= 0 && v < n);
}

// Function to insert
void ALGORITHM::insert(int u, int v, int w) 
{
    if (isvalid(u) && isvalid(v)) 
    {
        graph[u][v] = w;
        graph[v][u] = w;
    }
}

// Function to implement PRIM's ALGORITHM
void ALGORITHM::prims() 
{
    priority_queue< pair<int, pair<int, int>>, 
                    deque< pair<int, pair<int, int>> >, 
                    greater< pair<int, pair<int, int>> > > heap;
    int cost = 0;
    int edges = 0;
    for (int i = 0; i < n; i++) 
    {
        visited[i] = 0;
    }
    visited[0] = 1;
    for (int i = 0; i < n; i++) 
    {
        if (graph[0][i] != 0) 
        {
            heap.push({graph[0][i], {0, i}});
        }
    }
    cout << "Edges in the Minimum Spanning Tree: ";
    while (!heap.empty() && edges < n - 1) 
    {
        pair<int, pair<int, int>> edge = heap.top();
        heap.pop();
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (visited[v]) 
        {
            continue;
        }
        visited[v] = 1;
        cost += weight;
        edges++;
        cout << u + 1 << " -- " << v + 1 << " == " << weight << "\n";
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i] && graph[v][i] != 0) 
            {
                heap.push({graph[v][i], {v, i}});
            }
        }
    }
    cout << "Total cost of Minimum Spanning Tree: " << cost << "\n";
}

// Function to implement KRUSKAL's ALGORITHM
void ALGORITHM::kruskal() 
{
    int edges[100][3];
    int k = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (graph[i][j] != 0) 
            {
                edges[k][0] = i;
                edges[k][1] = j;
                edges[k][2] = graph[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i < k - 1; i++) 
    {
        for (int j = 0; j < k - i - 1; j++) 
        {
            if (edges[j][2] > edges[j + 1][2]) 
            {
                int temp0 = edges[j][0], temp1 = edges[j][1], temp2 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp0;
                edges[j + 1][1] = temp1;
                edges[j + 1][2] = temp2;
            }
        }
    }
    int parent[100];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int cost = 0;
    cout << "Edges in the Minimum Spanning Tree: ";
    for (int i = 0; i < k; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        int pu = u;
        while (pu != parent[pu]) 
        {
            pu = parent[pu];
        }
        int pv = v;
        while (pv != parent[pv]) 
        {
            pv = parent[pv];
        }
        if (pu != pv) 
        {
            cout << u + 1 << " -- " << v + 1 << " == " << w << "\n";
            cost += w;
            parent[pu] = pv;
        }
    }
    cout << "Total cost of Minimum Spanning Tree: " << cost << "\n";
}

// Function to implement DIJIKSTRA's ALGORITHM
void ALGORITHM::dijikstra() 
{
    int src;
    cout << "Enter the source vertex (1 to " << n << "): ";
    cin >> src;
    src--;
    int dist[100];
    bool visited[100];
    for (int i = 0; i < n; i++) 
    {
        dist[i] = 1000000;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) 
    {
        int min = 1000000, u;
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i] && dist[i] < min) 
            {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = true;
        for (int v = 0; v < n; v++) 
        {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Shortest distances from vertex " << src + 1 << ":\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "To vertex " << i + 1 << " => " << dist[i] << "\n";
    }
}

