#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//  Given a directed graph with positive weights and no self loop on any node
//  For code we will consider this graph
//  Algorithm complexity is O(n^3) where n is nodes in graph and only works for positive weights
//
//  Node to  Node cost Weight
//   0   to   1   cost  3
//   1   to   2   cost  6
//   1   to   4   cost  5
//   2   to   1   cost  2
//   2   to   3   cost  8
//   3   to   0   cost  1
//   3   to   1   cost  6
//   4   to   2   cost  3
//   4   to   3   cost  7
//
void build_empty_graph(vector <vector <ll>> &v1,ll &n)
{
    for(int i=0;i<n;i++)
    {
        vector <ll> v2(n,INT_MAX);
        v1.push_back(v2);
    }
}
void traverse(vector <vector <ll>> &v1)
{
    cout<<"\nMatrix representation of Graph\n";
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v1[i].size();j++)
        {
            if(v1[i][j]==INT_MAX) { cout<<"Inf ";continue; }
            cout<<v1[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void all_pair_shortest_path(vector <vector <ll>> &graph)
{
    ll current=-1;
    for(int k=0;k<graph.size();k++)
    {
        current++;
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                if(i==j) { graph[i][j]=0;continue; }
                if(i==current || j==current) continue;
                graph[i][j]=min(graph[i][current]+graph[current][j],graph[i][j]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,e;
    n=5;e=9;
    vector <vector <ll>> graph;
    build_empty_graph(graph,n);
    // use below commented syntax when you have to test input data;
    // cin>>n>>e;
    //while(e--) { ll node1,node2,weight; cin>>node1>>node2>>weight; graph[node1][node2]=weight; }
    graph[0][1]=3;
    graph[1][2]=6;
    graph[1][4]=5;
    graph[2][1]=2;
    graph[2][3]=8;
    graph[3][0]=1;
    graph[3][1]=6;
    graph[4][2]=3;
    graph[4][3]=7;
    cout<<"Given data\n";
    traverse(graph);
    all_pair_shortest_path(graph);
    cout<<"\nAfter applying Floyd Warshall's Algorithm\n";
    traverse(graph);
    return 0;