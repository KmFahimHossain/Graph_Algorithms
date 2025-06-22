#include <iostream>
#include <vector>
using namespace std;

// Cycle detect with DFS
bool detect_cycle_with_dfs(vector<vector<int>>& adj_list, vector<int>& visited, int node, int parent)
{
    visited[node] = 1;
    for(int neighbour : adj_list[node])
    {
        if(visited[neighbour] == 0)
        {
            if(detect_cycle_with_dfs(adj_list, visited, neighbour, node))
            {
                return true;
            }
        }
        else if(neighbour != parent)
        {
            return true;
        }
    }
    return false;
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
    bool cycle = 0;
    for(int i = 1; i < graph.size(); i++)
    {
        if(visited[i] == 0)
        {
            cycle = cycle || detect_cycle_with_dfs(graph, visited, i,-1);
            if(cycle == 1)
            {
                break;
            }
        }
    }
    cout<<cycle<<endl;
    return 0;
}

/* 
Inputs to check :
6 6
1 2
1 3
2 4
3 4
4 5
5 6

8 6
1 2
1 3
2 4
4 5
5 6
7 8
*/

// Date : 22.05.2025