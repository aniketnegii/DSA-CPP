#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Only applied in DAG - Directed Acyclic Graph
// Can be done using DFS and BFS

/*BFS method
    Indegree - Number of edges coming in.
    1. Calculate indegree
    2. Traverse all nodes and push the nodes with indegree 0 in the queue
    3. Take out the first element from queue and add it in the answer
    4. Reduce the indegree of adj nodes of the node you found in above step.
    5. If the in degree becomes 0 after reductiuon add it in the queue
    6. Repeat from step 3 until the queue is empty.
*/

/*
    TC ->
    SC ->
*/

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

    // calculate indegree
    vector<int> indegree(nodes, 0);
    for (auto nodes : adj)
    {
        for (auto node : nodes)
        {
            indegree[node] += 1;
        }
    }

    // bfs algo
    vector<int> ans;
    vector<int> vis(nodes, 0);
    queue<int> q; // to store topological order
    for (int i = 0; i < nodes; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto i : adj[node])
        {
            indegree[i] -= 1;
            if (indegree[i] == 0)
                q.push(i);
        }
    }

    for (auto node : ans)
    {
        cout << node << " ";
    }

    return 0;
}