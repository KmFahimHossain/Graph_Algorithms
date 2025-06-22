#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// graph in form {u --> v,w}
// Works with negative edge weights also , but graph needs to be directed
// As negative weight in undirected graph creates negative self cycle
// Works with directed or undirected both graphs if no negative weight edge
// Can detect negative weight cycle, returns -1
vector<int> bellman_ford(vector<vector<pair<int,int>>>& adj_list, int source, int V)
{
    vector<int> distance(V,INT_MAX); //Here V is actually no. of nodes + 1
    distance[source] = 0;
    for(int i = 1; i < V; i++)
    {
        for(int j = 1; j < V; j++)
        {
            for(pair<int,int> edge : adj_list[j])
            {
                int u = j;
                int v = edge.first;
                int w = edge.second;
                if(distance[u] != INT_MAX && distance[u] + w < distance[v])
                {
                    if( i == V-1)
                    {
                        return {-1,-1};
                    }
                    distance[v] = distance[u] + w;
                }
            }
        }
    }
    return distance;
}

vector<vector<pair<int,int>>> create_graph_directed()
{
    cout << "Give N and M (1-based directed weighted graph)" << endl;
    int n, m;
    cin >> n >> m;

    // Each element is a list of pairs: (neighbor, weight)
    vector<vector<pair<int, int>>> adj_list(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj_list[a].push_back({b, w});
    }
    return adj_list;
}

int main()
{
    vector<vector<pair<int,int>>> graph;
    graph = create_graph_directed();
    int source = 1;
    vector<int> dist = bellman_ford(graph, source, graph.size());
    cout<<"Shortest distance from "<<source<<" to all nodes are: ";
    for(int i = 1; i < dist.size(); i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* 
Inputs to check :
7 10
1 2 2
2 3 1
1 3 4
2 4 7
3 5 3
5 4 2
4 6 1
6 5 5
1 7 1
6 7 1

7 10
1 2 2
2 3 1
1 3 4
2 4 -7
3 5 3
5 4 2
4 6 1
6 5 5
1 7 1
6 7 1

7 10
1 2 2
2 3 1
1 3 4
2 4 7
3 5 3
5 4 2
4 6 1
6 5 -5
1 7 1
6 7 1
*/

// Date : 23.05.2025