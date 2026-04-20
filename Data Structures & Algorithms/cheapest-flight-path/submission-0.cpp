class Solution {
private:
    vector<vector<pair<int,int>>> buildAdj(int n, vector<vector<int>>& arr) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : arr) {
            int u = it[0] , v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        return adj;
    }
    vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int n, int k,int src, int dst){
        queue<pair<int,pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        pq.push({0,{0,src}});
        while(!pq.empty()) {
            auto [stops,it] = pq.front();
            pq.pop();
            int dis = it.first , u = it.second;
            for (auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;
                if (dis + wt < dist[v] && stops <= k) {
                    dist[v] = dis + wt;
                    pq.push({stops+1,{dist[v], v}});
                }
            }
        }
        return dist;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {
        auto adj = buildAdj(n,arr);
        auto dist = dijkstra(adj,n,k,src,dst);
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
