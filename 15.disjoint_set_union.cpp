#include <iostream>
#include <vector>
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

void create_disjoint_set(vector<vector<int>>& graph, int V, vector<int>& parents, vector<int>& rank)
{
    // Creating the parent vector
    for(int i = 1; i < V; i++)
    {
        parents[i] = i;
    }

    // Creating Disjoint Set Union
    for(int u = 1; u < V; u++)
    {
        for(int v : graph[u])
        {
            union_by_rank(parents,rank,u,v);
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
    return adj_list;
}

int main()
{
    vector<vector<int>> graph = create_graph();
    vector<int> parents(graph.size(), 0);
    vector<int> rank(graph.size(), 0);
    create_disjoint_set(graph, graph.size(),parents, rank);

    cout<<"Parents : ";
    for(int x : parents)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"Rank : ";
    for(int x : rank)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    int u,v;
    while(true)
    {
        cout<<"Enter u and v : ";
        cin>>u>>v;
        if(find_parent(parents,u) == find_parent(parents,v))
        {
            cout<<"Same connected component"<<endl;
        }
        else
        {
            cout<<"Different connected component"<<endl;
        }
    }
    return 0;
}

/* 
Inputs to check :
9 9
1 2
2 3
3 4
5 6
6 7
5 7
1 8
3 9
4 9
1 2
3 8
2 6
8 6

7 6
1 2
2 3
4 5
5 6
6 7
7 1
1 4
5 7
*/

// Date : 03.06.2025