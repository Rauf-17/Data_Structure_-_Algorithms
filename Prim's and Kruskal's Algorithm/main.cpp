#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 10001
#define INF 0x3f3f3f3f

vector<pair<int,int>> adj[MAX];
bool visited[MAX];


int prim(int start, int n)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int minCost = 0;

    pq.push(make_pair(0,start));

    while(!pq.empty())
    {
        pair<int,int> curr = pq.top();
        pq.pop();

        int u = curr.second;
        int w = curr.first;

        if(visited[u])
            continue;

        visited[u] = true;
        minCost += w;

        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if(!visited[v])
                pq.push(make_pair(weight, v));
        }
    }
    return minCost;
}

int parent[MAX];
int find(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

int kruskal(int n, vector<pair<int,pair<int,int>>> edges)
{
    int minCost = 0;
    sort(edges.begin(), edges.end());

    for(int i=1;i<=n;i++)
        parent[i] = i;

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        int parentU = find(u);
        int parentV = find(v);

        if(parentU != parentV)
        {
            parent[parentU] = parentV;
            minCost += w;
        }
    }
    return minCost;
}

int main()
{
    int n,m;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout<<"Enter edge "<<i+1<<" (u v w): ";
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    int start;
    cout<<"Enter starting vertex: ";
    cin>>start;

    int primMST = prim(start,n);
    cout<<"Minimum cost using Prim's algorithm: "<<primMST<<endl;

    vector<pair<int,pair<int,int>>> edges;
    for(int u=1;u<=n;u++)
    {
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            edges.push_back(make_pair(w,make_pair(u,v)));
        }
    }

    int kruskalMST = kruskal(n,edges);
    cout<<"Minimum cost using Kruskal's algorithm: "<<kruskalMST<<endl;

    return 0;
}
