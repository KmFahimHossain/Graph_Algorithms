#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Returns after finding one path from s to t
bool dfs(vector<vector<int>>& residual_graph, vector<int>& path, vector<bool>& visited, int node, int t)
{
    path.push_back(node);
    if(node == t) return true;

    visited[node] = true;
    for(int i = 0; i < residual_graph.size(); i++)
    {
        if(residual_graph[node][i] > 0 && visited[i] == false)
        {
            if(dfs(residual_graph,path, visited, i, t)) return true;
        }
    }
    path.pop_back();
    return false;
}

int ford_fulkerson(vector<vector<int>>& capacity_graph, int s, int t)
{
    vector<vector<int>> residual_graph = capacity_graph;
    int n = capacity_graph.size();
    vector<int> path;
    vector<bool> visited (n,false);
    int max_flow = 0;

    while(dfs(residual_graph, path, visited, s, t))
    {
        int path_flow = INT_MAX;
        for(int i = 0; i < path.size() - 1; i++)
        {
            int u = path[i];
            int v = path[i+1];
            path_flow = min(path_flow, residual_graph[u][v]);
        }
        
        for(int i = 0; i < path.size() - 1; i++)
        {
            int u = path[i];
            int v = path[i+1];
            residual_graph[u][v] -= path_flow;
            residual_graph[v][u] += path_flow;
        }
        max_flow += path_flow;
        path.clear();
        fill(visited.begin(), visited.end(), false);
        cout<<"Path flow : "<<path_flow<<endl;
    }
    return max_flow;
}

vector<vector<int>> create_graph()
{
    cout<<"Give N and M (0-based directed weighted graph)"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_matrix(n, vector<int>(n,0));
    for(int i = 0; i < m; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj_matrix[a][b] = w;
    }
    return adj_matrix;
}

int main()
{
    vector<vector<int>> capacity_graph = create_graph();
    int source,target;
    cout<<"Enter source and sink : "<<endl;
    cin>>source>>target;
    cout<<"Max flow : "<<ford_fulkerson(capacity_graph, source, target)<<endl;
    return 0;
}

/* 
Inputs to check :
6 9
0 1 10
0 3 10
1 3 2
1 2 4
3 4 9
1 4 8
4 2 6
2 5 10
4 5 10
0 5
Ans : 19

4 5
0 1 1
2 0 100
2 1 100
0 3 100
1 3 100
2 3
Ans : 200

6 10
0 1 16
0 2 13
1 2 10
2 1 4
1 3 12
3 2 9
2 4 14
4 3 7
4 5 4
3 5 20
0 5
Ans : 23
*/

// Date : 21.06.2025