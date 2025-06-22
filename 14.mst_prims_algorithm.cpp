#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// graph in form {u --> v,w}, also the graph should be connected
// Finds the sum of the MST
int prims_algorithm(vector<vector<pair<int,int>>>& adj_list, int V)
{
    int sum = 0;
    vector<bool> visited(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {w,u} = {weight, current}
    pq.push({0,1}); 
    while(!pq.empty())
    {
        int current= pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if(visited[current] == false)
        {
            sum += weight;
            visited[current] = true;
        }

        for(pair<int,int>& neighbour : adj_list[current])
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if(visited[v] == false)
            {
                pq.push({w,v});
            }
        }
    }
    return sum;
}

// // Finds the edges that are selected to form the MST
vector<pair<int,int>> prims_algorithm_with_edges(vector<vector<pair<int,int>>>& adj_list, int V)
{
    vector<pair<int,int>> selected_edges;
    int sum = 0;
    vector<bool> visited(V, false);
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq; //{w,u,v} = {weight,parent,current}
    pq.push({0,0,1});
    while(!pq.empty())
    {
        int weight = get<0>(pq.top());
        int parent = get<1>(pq.top());
        int current = get<2>(pq.top());
        pq.pop();
        if(visited[current] == false)
        {
            if(parent != 0)
            {
                selected_edges.push_back({parent,current});
                sum += weight;
            }
            visited[current] = true;
        }

        for(pair<int,int>& neighbour : adj_list[current])
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if(visited[v] == false)
            {
                pq.push({w,current,v});
            }
        }
    }
    cout<<sum<<endl;
    return selected_edges;
}

vector<vector<pair<int,int>>> create_graph()
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

int main()
{
    vector<vector<pair<int,int>>> graph;
    graph = create_graph();
    int mst_sum = prims_algorithm(graph, graph.size());
    cout<<mst_sum<<endl;

    vector<pair<int,int>> selected_edges = prims_algorithm_with_edges(graph, graph.size());
    for(pair<int,int>& edges : selected_edges)
    {
        cout<<edges.first<<" "<<edges.second<<endl;
    }
    return 0;
}

/* 
Inputs to check :
5 6
1 2 2
1 3 1
2 3 1
3 5 2
5 4 1
3 4 2

3 3
1 2 5
2 3 3
1 3 1

6 9
5 4 9
5 1 4
4 1 1
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/

// Date : 03.06.2025