#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkBipartite(int node, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;
    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();
        for (auto it : adj[currNode])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[currNode];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkBFS(vector<int> adj[], int nodes)
{
    vector<int> color(nodes + 1, -1);
    for (int i = 1; i <= nodes; i++)
    {
        if (color[i] == -1)
        {
            if (!checkBipartite(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes + 1];
    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Bipartite Graph:" << checkBFS(adj, nodes) << endl;

    return 0;
}