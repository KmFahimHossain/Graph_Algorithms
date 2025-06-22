#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// FLoyd-Warshall Algorithm, Works with negative weights also
// For negative weights, graph needs to be directed
vector<vector<int>> floyd_warshall(vector<vector<int>>& graph, int V)
{
    vector<vector<int>> shortest_distances(V, vector<int>(V,INT_MAX));
    for(int i = 1; i < V; i++)
    {
        for(int j = 1; j < V; j++)
        {
            shortest_distances[i][j] = graph[i][j];
        }
    }

    for(int k = 1; k < V; k++)
    {
        for(int i = 1; i < V; i++)
        {
            for(int j = 1; j < V; j++)
            {
                if(shortest_distances[i][k] != INT_MAX && shortest_distances[k][j] != INT_MAX &&
                   shortest_distances[i][k] + shortest_distances[k][j] < shortest_distances[i][j])
                {
                    shortest_distances[i][j] = shortest_distances[i][k] + shortest_distances[k][j];
                }
            }
        }
    }

    for(int i = 1; i <V; i++)
    {
        if(shortest_distances[i][i] < 0)
        {
            return {{},{0,-1}};
        }
    }
    return shortest_distances;
}

vector<vector<int>> create_graph_undirected()
{
    cout<<"Give N and M (1-based undirected weighted graph)"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_matrix(n+1, vector<int>(n+1,INT_MAX));
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            if(i==j)
            {
                adj_matrix[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj_matrix[a][b] = w;
        adj_matrix[b][a] = w;
    }
    return adj_matrix;
}

vector<vector<int>> create_graph_directed()
{
    cout<<"Give N and M (1-based directed weighted graph)"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_matrix(n+1, vector<int>(n+1,INT_MAX));
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            if(i==j)
            {
                adj_matrix[i][j] = 0;
            }
        }
    }
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
    vector<vector<int>> graph;
    graph = create_graph_directed();
    int n = graph.size();
    vector<vector<int>> shortest_distance = floyd_warshall(graph, n);

    for(int i = 1; i < shortest_distance.size(); i++)
    {
        for(int j = 1; j < shortest_distance[1].size(); j++)
        {
            if(shortest_distance[i][j] != INT_MAX)
            {
                cout<<shortest_distance[i][j]<<" ";
            }
            else
            {
                cout<<"I ";
            }
        }
        cout<<endl;
    }
    return 0;
}

/* 
Inputs to check :
8 10
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 2
4 6 1
5 6 5
1 7 1
7 6 1

7 10
1 2 2
1 3 4
2 3 1
2 4 -7
3 5 3
4 5 2
4 6 1
5 6 5
1 7 1
7 6 1

7 10
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 2
6 4 1
5 6 -5
1 7 1
7 6 1
*/

// Date : 26.05.2025