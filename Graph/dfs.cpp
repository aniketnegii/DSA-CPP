#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[], int v, int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int>adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i<<": ";
        for(int x: adj[i])
        {
            cout<<x<<" ";
        }
    cout<<"\n";
    }
}

void DFSrec(vector<int>adj[],int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int u: adj[s])
    {
        if(visited[u]==false)
        {
            DFSrec(adj,u,visited);
        }
    }
}

void DFS(vector<int>adj[], int v)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i]=false;
    int s = 0;
    DFSrec(adj,s,visited);
}

int main()
{
    int v = 5;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    cout<<"\nAuthor: Abhishek Kumar\n\nAdjancy list representation:\n";
    printGraph(adj,v);
    cout<<"\nDFS of graph is: ";
    DFS(adj,v);
    cout<<"\n\n";
    return 0;
}