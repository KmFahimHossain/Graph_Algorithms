#include <iostream>
#include <vector>
using namespace std;

// Finds all paths from s to t
void dfs(vector<vector<int>>& adj_matrix, vector<vector<int>>& all_paths, vector<int>& path, vector<bool>& visited, int t, int node)
{
    if(node == t)
    {
        path.push_back(node);
        all_paths.push_back(path);
        path.pop_back();
        return;
    }

    path.push_back(node);
    visited[node] = true;
    for(int i = 0; i < adj_matrix.size(); i++)
    {
        if(adj_matrix[node][i] != 0 && visited[i] == false)
        {
            dfs(adj_matrix, all_paths, path, visited, t, i);
        }
    }
    path.pop_back();
    visited[node] = false;
}

vector<vector<int>> create_graph()
{
    cout<<"Give N and M(0-based directed graph)"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_matrix(n, vector<int>(n,0));
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj_matrix[a][b] = 1;
    }
    return adj_matrix;
}

int main()
{
    vector<vector<int>> graph = create_graph();
    int source,target;
    cin>>source>>target;
    vector<vector<int>> all_paths;
    vector<int> path;
    vector<bool> visited (graph.size(), false);
    dfs(graph,all_paths,path,visited,target,source);

    cout<<"Printing all possible paths from "<<source<<" to "<<target<<" : "<<endl;
    for(vector<int>& path : all_paths)
    {
        for(int x : path)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<"Total paths : "<<all_paths.size();
    return 0;
}

/* 
Inputs to check :
6 9
0 1
1 2
2 5
0 3
3 1
3 4
1 4
4 2
4 5
0 5
*/

// Date : 21.06.2025