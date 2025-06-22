#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// graph in form {u --> v,w}
// Dijkstra constraints : No negative edge weights
vector<int> dijkstra(vector<vector<pair<int,int>>>& adj_list, int source, int V)
{
    vector<int> distance(V,INT_MAX); //Here V is actually no. of nodes + 1
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

vector<int> dijkstra_with_route(vector<vector<pair<int,int>>>& adj_list, int source, int destination, int V)
{
    vector<int> distance(V,INT_MAX); //Here V is actually no. of nodes + 1
    vector<int> parents(V,-1);
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
                parents[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
    
    vector<int> route;
    route.push_back(destination);
    while(destination != source)
    {
        if (parents[destination] == -1) 
        {
            return {}; // no path exists
        }
        destination = parents[destination];
        route.push_back(destination);
    }
    reverse(route.begin(), route.end());
    return route;
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
    graph = create_graph_undirected();
    int source = 1;
    int destination = 4;
    vector<int> dist = dijkstra(graph, source, graph.size());
    cout<<"Shortest distance from "<<source<<" to all nodes are: ";
    for(int i = 1; i < dist.size(); i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    vector<int> route = dijkstra_with_route(graph, source, destination, graph.size());
    cout<<"Shortest path from "<<source<<" to "<<destination<<" is: ";
    for(int i = 0; i < route.size(); i++)
    {
        cout<<route[i]<<" ";
    }
    return 0;
}

/* 
Inputs to check :

7 10
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
2 3 1
1 3 4
2 4 7
3 5 3
5 4 2
4 6 1
6 5 5
1 7 1
6 7 1
*/

// Date : 23.05.2025