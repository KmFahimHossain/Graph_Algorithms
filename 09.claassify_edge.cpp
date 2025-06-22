#include <iostream>
#include <vector>
using namespace std;

// Tree Edge: Part of the DFS tree, leads to an unvisited node.
// Forward Edge: (u → v), v is a descendant of u, not in DFS tree.
// Back Edge: (u → v), v is an ancestor of u — indicates a cycle.
// Cross Edge: Connects nodes with no ancestor-descendant relation.

// Edge Classification during DFS:
// 0 → Tree Edge: if v is unvisited.
// 1 → Back Edge: v already visited,v is in recursion stack — indicates a cycle.
// 2 → Forward Edge: v is visited, not in stack, and discovery[u] < discovery[v].
// 3 → Cross Edge: v is visited, not in stack, and discovery[u] > discovery[v].

void classify_edge(vector<vector<pair<int,int>>>& classified_edges, vector<vector<int>>& adj_list, 
                   vector<bool>& visited, vector<int>& discovery, vector<bool>& inStack, int node, int& time)
{
    visited[node] = true;
    inStack[node] = true;
    discovery[node] = time;
    time++;
    for(int neighbour : adj_list[node])
    {
        if(visited[neighbour] == false)
        {
            classified_edges[0].push_back({node,neighbour});
            classify_edge(classified_edges, adj_list, visited, discovery, inStack, neighbour,time);
        }
        else if(inStack[neighbour] == true)
        {
            classified_edges[1].push_back({node,neighbour});
        }
        else if(discovery[neighbour] > discovery[node])
        {
            classified_edges[2].push_back({node,neighbour});
        }
        else if(discovery[neighbour] < discovery[node])
        {
            classified_edges[3].push_back({node,neighbour});
        }
    }
    inStack[node] = false;
}

vector<vector<int>> create_graph()
{
    cout << "Give N and M (1-based directed graph)" << endl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_list(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    return adj_list;
}

int main()
{
    vector<vector<int>> graph = create_graph();
    vector<vector<pair<int,int>>> edges(4);
    vector<string> edge_types = {"Tree Edge", "Back Edge", "Forward Edge", "Cross Edge"};
    vector<bool> visited(graph.size(), false);
    vector<int> discovery(graph.size(), 0);
    vector<bool> inStack(graph.size(), false);
    int time = 1;

    for(int i = 1; i < graph.size(); i++)
    {
        if(visited[i] == false)
        {
            classify_edge(edges,graph,visited,discovery,inStack,i,time);
        }
    }

    for(int i = 0; i < 4; i++)
    {
        cout<<edge_types[i]<<": ";
        for(pair<int,int> single_edge : edges[i])
        {
            cout<<single_edge.first<<"-->"<<single_edge.second<<", ";
        }
        cout<<endl;
    }
    return 0;
}

/* 
Inputs to check :
8 10
1 2
1 3
2 4
3 5
4 6
6 2
5 4
5 7
5 8
1 8

9 12
1 2
1 3
3 4
2 4
4 5
5 5
5 6
7 8
7 9
9 8
5 2
1 4
*/

// Date : 23.05.2025