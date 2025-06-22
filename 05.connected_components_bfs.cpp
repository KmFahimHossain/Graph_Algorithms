#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS traversing in connected graph
void bfs_connected_graph(vector<vector<int>>& adj_list, vector<int>& visited, int source)
{
    visited[source] = 1;
    queue<int> q;
    q.push(source);

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(int neighbour : adj_list[top])
        {
            if(visited[neighbour] == 0)
            {
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
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
    return adj_list;
}

int main()
{
    vector<vector<int>> graph = create_graph();
    vector<int> visited(graph.size(), 0);
    int count = 0;
    for(int i = 1; i < graph.size(); i++)
    {
        if(visited[i] == 0)
        {
            bfs_connected_graph(graph, visited, i);
            count++;
        }
    }
    cout<<"No of connected components: "<<count<<endl;
    return 0;
}

/* 
Inputs to check :
10 8
1 2
1 3
2 4
3 4
5 6
5 7
6 7
8 9
*/

// Date : 22.05.2025