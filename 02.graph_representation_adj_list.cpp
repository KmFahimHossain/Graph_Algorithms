#include <iostream>
#include <vector>
using namespace std;

// 1-based undirected graph taking input, storing and output(print) using Adj. list
void graph_list1()
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

    cout << "Printing Adj. List form of the Graph" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int neighbor : adj_list[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << "Done Printing" << endl;
}

// 1-based directed graph taking input, storing and output(print) using Adj. list
void graph_list2()
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

    cout << "Printing Adj. List form of the Graph" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int neighbor : adj_list[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << "Done Printing" << endl;
}

// 1-based undirected weighted graph taking input, storing and output(print) using Adj. list
void graph_list3()
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

    cout << "Printing Adj. List form of the Graph" << endl;
    for (int i = 1; i < n+1; i++)
    {
        cout << i << ": ";
        for (auto p : adj_list[i])
        {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
    cout << "Done Printing" << endl;
}

// 1-based directed weighted graph taking input, storing and output(print) using Adj. list
void graph_list4()
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

    cout << "Printing Adj. List form of the Graph" << endl;
    for (int i = 1; i < n+1; i++)
    {
        cout << i << ": ";
        for (auto p : adj_list[i])
        {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
    cout << "Done Printing" << endl;
}

int main()
{
    graph_list1();
    // graph_list2();
    // graph_list3();
    // graph_list4();
    return 0;
}

/* 
Inputs to check :
5 6
1 2
1 3
2 4
3 4
3 5
4 5

5 6
1 2 3
1 3 2
3 4 1
2 4 4
3 5 4
4 5 3
*/

// Date : 16.05.2025