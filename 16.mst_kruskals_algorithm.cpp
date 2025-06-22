#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Gives 'Ultimate Parent' for a node, also stores that in parents vector
int find_parent(vector<int>& parents, int node)
{
    if(parents[node] == node)
    {
        return node;
    }
    parents[node] = find_parent(parents,parents[node]);
    return parents[node];
}

void union_by_rank(vector<int>& parents, vector<int>& rank, int u, int v)
{
    int up_u = find_parent(parents,u);
    int up_v = find_parent(parents,v);
    if(up_u == up_v)
    {
        return;
    }

    if(rank[up_u] == rank[up_v])
    {
        parents[up_v] = up_u;
        rank[up_u]++;
    }
    else if(rank[up_u] > rank[up_v])
    {
        parents[up_v] = up_u;
    }
    else if(rank[up_u] < rank[up_v])
    {
        parents[up_u] = up_v;
    }
}

// Adj_list in form {u -> v,w}
vector<pair<int,int>> kruskals_algorithm(vector<vector<pair<int,int>>>& adj_list, int V, int& sum)
{
    // Create different form of edges {w,{u,v}}, so that edges can be sort 
    vector<pair<int,pair<int,int>>> edges;
    for(int i = 1; i < V; i++)
    {
        for(pair<int,int>& edge : adj_list[i])
        {
            edges.push_back({edge.second,{i,edge.first}});
        }
    }
    sort(edges.begin(),edges.end());
    // Sorted new form of edges
    // for(pair<int,pair<int,int>>& edge : edges)
    // {
    //     cout<<edge.first<<" "<<edge.second.first<<" "<<edge.second.second<<endl;
    // }

    vector<int> rank(adj_list.size(), 0);
    vector<int> parents(adj_list.size(), 0);
    for(int i = 1; i < V; i++)
    {
        parents[i] = i;
    }

    vector<pair<int,int>> selected_edges;
    for(pair<int,pair<int,int>>& edge : edges)
    {
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;
        if(find_parent(parents,u) != find_parent(parents,v))
        {
            selected_edges.push_back({u,v});
            sum += w;
        }
        union_by_rank(parents,rank,u,v);
    }
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

    int mst_sum = 0;
    vector<pair<int,int>> selected_edges = kruskals_algorithm(graph, graph.size(), mst_sum);
    for(pair<int,int>& edges : selected_edges)
    {
        cout<<edges.first<<" "<<edges.second<<endl;
    }
    cout<<mst_sum;
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

// Date : 04.06.2025