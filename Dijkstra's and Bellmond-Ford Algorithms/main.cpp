#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f


void dijkstra(int graph[][5], int V, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < V; ++v)
	    {
            if (graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
		    {
                dist[v] = dist[u] + graph[u][v];
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Shortest path distances from vertex " << src << " to all other vertices using Dijkstra's algorithm:\n";

    for (int i = 0; i < V; ++i)
	{
        cout << i << ": " << dist[i] << "\n";
   	}
}


void bellmanFord(int graph[][5], int V, int src)

{
    vector<int> dist(V, INF);
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i)
	{
        for (int u = 0; u < V; ++u)
		{

            for (int v = 0; v < V; ++v)
			{
                if (graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
				 {
                    dist[v] = dist[u] + graph[u][v];
               	 }
           	}
       	}
    }

    cout << "Shortest path distances from vertex " << src << " to all other vertices using Bellman-Ford algorithm:\n";

    for (int i = 0; i < V; ++i)
	{
        cout << i << ": " << dist[i] << "\n";
    }
}

int main()
{
    int V, E, graph[5][5], src,n;
    cout << "Enter the number of vertices : ";
    cin >> V;
    cout<< "Enter the number of edges : ";
    cin>> E;

    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; ++i)
	{
        for (int j = 0; j < V; ++j)
	    {
            cout << "[" << i+1 << "][" << j+1 << "]=";
            cin >> graph[i][j];
        }

    }


    cout << "Enter the source vertex : ";
    cin >> src;

    int choice;
    cout << "Enter 1 to run Dijkstra's algorithm or 2 to run Bellman-Ford algorithm : ";
    cin >> choice;

    if (choice == 1)
	{
        dijkstra(graph, V, src);
	}
	else if (choice == 2)
	{
        bellmanFord(graph, V, src);
    }

	else
	{
        cout << "Invalid choice!\n";
	}

    return 0;
}

