#include "App.h"

App::App()	{}

std::vector < std::vector <int> > App::graphInit()
{
    int e = 0, v = 0, from, to, weight;

    std::cout << "Enter the number of vertices: ";
    std::cin >> v;
    std::cout << "Enter the number of edges: ";
    std::cin >> e;

    std::vector < std::vector <int> > graph(v, std::vector<int>(v));

    std::cout << std::endl << "Enter the edges (from, to, weight):" << std::endl;
   
    while (e > 0)
    {
        std::cin >> from;
        std::cin >> to;
        std::cin >> weight;

        graph[int(from)-1][int(to)-1] = int(weight);
        graph[int(to)-1][int(from)-1] = int(weight);

        e--;
    }
    std::cout << std::endl;

    return graph;
}

void App::primsAlgorithm(std::vector < std::vector <int> > graph)
{
    int v = graph.size();

    std::vector <int> parent(v);
    std::vector <int> key(v);
    std::vector <bool> vis(v);

    std::priority_queue<std::pair<int, int>,
    std::vector<std::pair<int, int>>,
    std::greater<std::pair<int, int>>> pq;

    for (int i = 0; i < v; i++) {
        key[i] = INT_MAX;
        vis[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
    pq.push({ 0, 0 });

    while (!pq.empty()) 
    {
        int node = pq.top().second;
        pq.pop();
        vis[node] = true;
        for (int i = 0; i < v; i++) 
        {
            if (!vis[i] && graph[node][i] != 0
                && graph[node][i] < key[i]) 
            {
                pq.push({ graph[node][i], i });
                key[i] = graph[node][i];
                parent[i] = node;
            }
        }
    }
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < v; i++) {
        std::cout << parent[i]+1 << " - " << i+1
            << " \t" << graph[i][parent[i]] << " \n";
    }
}