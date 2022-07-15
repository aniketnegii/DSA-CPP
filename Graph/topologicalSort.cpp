#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Only applied in DAG - Directed Acyclic Graph
// Can be done using DFS and BFS

/*DFS method

    1. for i = 1 to nodes,
        call dfs(i) and mark vis[i] = 1
    2. After you return from dfs call add the i in stack
*/

/*
    TC -> O(N + E)
    SC -> O(N) + O(N)
*/

void dfs(int i, vector<int> adj[], vector<int> &vis, stack<int> &s)
{

    for (auto node : adj[i])
    {
        if (vis[node] == 0)
        {
            dfs(node, adj, vis, s);
            vis[node] = 1;
            s.push(node);
        }
    }
}

int main()
{

    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj[nodes];
    for (int i = 0; i < nodes; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed graph
    }

    // dfs algo
    vector<int> vis(nodes, 0);
    stack<int> s; // to store topological order

    for (int i = 0; i < nodes; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, vis, s);
            vis[i] = 1;
            s.push(i);
        }
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}