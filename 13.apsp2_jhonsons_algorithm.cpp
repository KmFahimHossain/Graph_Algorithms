#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj_list, int source, int V)
{
    vector<int> distance(V,INT_MAX);
    distance[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min-heap
    pq.push({0, source});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(pair<int,int> neighbour : adj_list[u]) // Here neighbour_pair = {v,w}
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if(distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}

vector<int> bellman_ford(vector<vector<pair<int,int>>>& adj_list, int source, int V)
{
    vector<int> distance(V,INT_MAX);
    distance[source] = 0;
    for(int i = 0; i < V-1 ; i++)
    {
        for(int j = 0; j < V; j++)
        {
            for(pair<int,int>& edge : adj_list[j])
            {
                int u = j;
                int v = edge.first;
                int w = edge.second;
                if(distance[u] != INT_MAX && distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }
    return distance;
}

// graph in form {u --> v,w}
// Johnson's Algorithm, Works with negative weights also
// For negative weights, graph needs to be directed
// Combines Dijkstra with Bellman-ford algorithm
vector<vector<int>> jhonsons_algorithm(vector<vector<pair<int,int>>>& adj_list, int V)
{
    // Creating a new node : 0
    for(int i = 1; i < V; i++)
    {
        adj_list[0].push_back({i,0});
    }
    
    // Reweighting
    vector<int> distance = bellman_ford(adj_list, 0, V);
    for(int i = 1; i < V; i++)
    {
        for(pair<int,int>& edge : adj_list[i])
        {
            int u = i;
            int v = edge.first;
            edge.second = distance[u] + edge.second - distance[v];
        }
    }
    
    // Graph after reweighting
    // cout<<"Graph after Reweighting"<<endl;
    // for (int i = 1; i < V; i++)
    // {
    //     cout << i << ": ";
    //     for (pair<int,int> edge : adj_list[i])
    //     {
    //         cout << "(" << edge.first << ", " << edge.second << ") ";
    //     }
    //     cout << endl;
    // }

    // Dijkstra for each node
    vector<vector<int>> shortest_distances;
    for(int i = 0; i < V; i++)
    {
        shortest_distances.push_back(dijkstra(adj_list, i, V));
    }

    // Back to previous weight forms
    for(int i = 1; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(shortest_distances[i][j] != INT_MAX)
            {
                shortest_distances[i][j] += (distance[j] - distance[i]);
            }
        }
    }
    return shortest_distances;
}

vector<vector<pair<int,int>>> create_graph_undirected()
{
    cout << "Give N and M (1-based undirected weighted graph)" << endl;
    int n, m;
    cin >> n >> m;

    // Each element is a list of pairs: (neighbor, weight)
    vector<vector<pair<int, int>>> adj_list(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});
    }
    return adj_list;
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
    int n = graph.size();

    vector<vector<int>> shortest_distance = jhonsons_algorithm(graph, n);
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
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

5 6
1 2 4
1 5 1
5 4 -5
4 2 1
3 4 -2
3 2 7 
*/

// Date : 26.05.2025