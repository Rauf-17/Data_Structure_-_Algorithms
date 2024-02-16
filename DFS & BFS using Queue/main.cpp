#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void DFS(vector<int> adj[], int V, int startVertex)
{
    vector<bool> visited(V, false);
    stack<int> stack;

    stack.push(startVertex);
    visited[startVertex] = true;

    while (!stack.empty()) {
        int currVertex = stack.top();
        stack.pop();

        cout << currVertex << " ";

        for (int adjacent : adj[currVertex]) {
            if (!visited[adjacent]) {
                stack.push(adjacent);
                visited[adjacent] = true;
            }
        }
    }
}

void BFS(vector<int> adj[], int V, int startVertex)
{
    vector<bool> visited(V, false);
    queue<int> queue;

    queue.push(startVertex);
    visited[startVertex] = true;

    while (!queue.empty()) {
        int currVertex = queue.front();
        queue.pop();

        cout << currVertex << " ";

        for (int adjacent : adj[currVertex]) {
            if (!visited[adjacent]) {
                queue.push(adjacent);
                visited[adjacent] = true;
            }
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertexes: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];

    cout << "Enter the edges source and destination:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "DFS traversal: ";
    DFS(adj, V, startVertex);
    cout << endl;

    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS traversal: ";
    BFS(adj, V, startVertex);
    cout << endl;

    return 0;
}

