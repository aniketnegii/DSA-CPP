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

void BFS(vector<int>adj[],int s,int v)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i]=false;
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        for(int s: adj[x])
        {
            if (visited[s]==false)
            {
                visited[s]=true;
                q.push(s);
            }
        }
    }
}

int main()
{
    int v = 5;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    cout<<"\nAuthor: Abhishek Kumar\n\nAdjancy list representation:\n";
    printGraph(adj,v);
    cout<<"\nBFS of Graph is: ";
    int s = 0;
    BFS(adj,s,v);
    cout<<"\n\n";
    return 0;
}