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

vector<vector<int>> ford_fulkerson_residual_graph(vector<vector<int>>& capacity_graph, int s, int t)
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
    }
    cout<<"Max flow : " <<max_flow<<endl;
    return residual_graph;
}

void dfs_reachable(vector<vector<int>>& residual_graph, vector<bool>& visited, int node)
{
    visited[node] = true;
    for(int i = 0; i < residual_graph.size(); i++)
    {
        if(residual_graph[node][i] > 0 && visited[i] == false)
        {
            dfs_reachable(residual_graph,visited, i);
        }
    }
    return;
}

vector<pair<int,int>> find_min_cut(vector<vector<int>>& capacity_graph, int s, int t)
{
    vector<pair<int,int>> min_cut_edges;
    int n = capacity_graph.size();
    vector<vector<int>> residual_graph = ford_fulkerson_residual_graph(capacity_graph, s, t);
    vector<bool> visited (n,false);
    dfs_reachable(residual_graph, visited, s);

    for(int u = 0; u < n; u++)
    {
        if(visited[u])
        {
            for(int v = 0; v < n; v++)
            {
                if(visited[v] == false && capacity_graph[u][v] > 0)
                {
                    min_cut_edges.push_back({u,v});
                }
            }
        }
    }
    return min_cut_edges;
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
    vector<vector<int>> graph = create_graph();
    int source, target;
    cout<<"Give s and t : "<<endl;
    cin>>source>>target;
    vector<pair<int,int>> min_cut_edges = find_min_cut(graph, source, target);

    for(pair<int,int>& edge : min_cut_edges)
    {
        cout<<edge.first<<" -> "<<edge.second<<" capacity("<<graph[edge.first][edge.second]<<")"<<endl;
    }
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

4 5
0 1 1
2 0 100
2 1 100
0 3 100
1 3 100
2 3

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
*/

// Date : 21.06.2025