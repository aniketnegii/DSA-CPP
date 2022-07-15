// We can represent the graph in adjacents matrix 
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;  // Here n is no. of nodes & m is edges present in graph 
    cin>>n>>m; 

    // Taking input of adjacent matrix
    int adj[n+1][n+1];

    // assigning the value 1 if the value present in graph.
    for(int i=0; i<m; i++){
        int v,u;
        cin >>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}