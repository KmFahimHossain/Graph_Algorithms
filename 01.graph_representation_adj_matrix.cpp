#include <iostream>
#include <vector>
using namespace std;

// 1-based undirected graph taking input, storing and output(print) using Adj. matrix
void graph_matrix1()
{
    cout<<"Give N and M (1-based undirected graph)"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_matrix(n+1, vector<int>(n+1,0));
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
    
    cout<<"Printing Adj. Matrix form of the Graph"<<endl;
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Done Printing"<<endl;
}

// 0-based undirected graph taking input, storing and output(print) using Adj. matrix
void graph_matrix2()
{
    cout<<"Give N and M(0-based undirected graph)"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_matrix(n, vector<int>(n,0));
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
    
    cout<<"Printing Adj. Matrix form of the Graph"<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Done Printing"<<endl;
}

// 1-based directed graph taking input, storing and output(print) using Adj. matrix
void graph_matrix3()
{
    cout<<"Give N and M (1-based directed graph)"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_matrix(n+1, vector<int>(n+1,0));
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj_matrix[a][b] = 1;
    }
    
    cout<<"Printing Adj. Matrix form of the Graph"<<endl;
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Done Printing"<<endl;
}

// 0-based directed graph taking input, storing and output(print) using Adj. matrix
void graph_matrix4()
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
    
    cout<<"Printing Adj. Matrix form of the Graph"<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Done Printing"<<endl;
}

// 1-based undirected weighted graph taking input, storing and output(print) using Adj. matrix
void graph_matrix5()
{
    cout<<"Give N and M (1-based undirected weighted graph)"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_matrix(n+1, vector<int>(n+1,0));
    for(int i = 0; i < m; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj_matrix[a][b] = w;
        adj_matrix[b][a] = w;
    }
    
    cout<<"Printing Adj. Matrix form of the Graph"<<endl;
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Done Printing"<<endl;
}

// 1-based directed weighted graph taking input, storing and output(print) using Adj. matrix
void graph_matrix6()
{
    cout<<"Give N and M (1-based directed weighted graph)"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_matrix(n+1, vector<int>(n+1,0));
    for(int i = 0; i < m; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj_matrix[a][b] = w;
    }
    
    cout<<"Printing Adj. Matrix form of the Graph"<<endl;
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Done Printing"<<endl;
}

int main()
{
    graph_matrix1();
    // graph_matrix2();
    // graph_matrix3();
    // graph_matrix4();
    // graph_matrix5();
    // graph_matrix6();
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
1 2
1 3
2 4
3 4
3 0
4 0 

5 6
1 2 3
1 3 2
3 4 1
2 4 4
3 5 4
4 5 3
*/

// Date : 16.05.2025