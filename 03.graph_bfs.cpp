#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS traversing in connected graph
void bfs_connected_graph(vector<vector<int>>& adj_list, vector<int>& visited, int source)
{
    cout<<"BFS Function called with source "<<source<<endl;
    visited[source] = 1;
    queue<int> q;
    q.push(source);

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        cout<<top<<" ";
        for(int neighbour : adj_list[top])
        {
            if(visited[neighbour] == 0)
            {
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
    cout<<endl;
}

vector<vector<int>> create_graph()
{
    cout << "Give N and M (1-based undirected graph)" << endl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_list(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    cout << "Printing Adj. List form of the Graph" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int neighbor : adj_list[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << "Done Printing" << endl;
    return adj_list;
}

int main()
{
    vector<vector<int>> graph = create_graph();
    vector<int> visited(graph.size(), 0);
    for(int i = 1; i < graph.size(); i++)
    {
        if(visited[i] == 0)
        {
            bfs_connected_graph(graph, visited, i);
        }
    }
    cout<<"END";
    return 0;
}

/* 
Inputs to check :
14 11
1 2
2 3
2 4
1 6
6 7
6 9
4 5
7 8
5 8
10 11
11 12
*/

// Date : 17.05.2025