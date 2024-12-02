#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int dijkstra(vector<vector<pair<int, int>>>& graph, int n, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<
                        pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>>
        > pq;

        pq.emplace(0, src);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int max_dist = *max_element(dist.begin(), dist.end());
        return (max_dist == INT_MAX) ? -1 : max_dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for (const auto& edge : times) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int w = edge[2];
            graph[u].emplace_back(v, w);
        }

        return dijkstra(graph, n, k-1);
    }
};
