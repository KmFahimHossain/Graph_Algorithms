#include <iostream>
#include <vector>
using namespace std;

// DFS traversing in connected graph
void dfs(vector<vector<int>>& adj_list, vector<int>& visited, int node)
{
    cout<<node<<" ";
    visited[node] = 1;
    for(int neighbour : adj_list[node])
    {
        if(visited[neighbour] == 0)
        {
            dfs(adj_list, visited, neighbour);
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
            cout<<"DFS Function being called with "<<i<<endl;
            dfs(graph, visited, i);
            cout<<endl;
        }
    }
    cout<<"END";
    return 0;
}

/* 
Inputs to check :
17 14
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
1 15
15 16
15 17
*/

// Date : 17.05.2025