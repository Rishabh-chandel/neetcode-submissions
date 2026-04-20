class Solution {
private:
    vector<vector<pair<int,int>>> buildAdj(int n, vector<vector<int>>& arr) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : arr) {
            int u = it[0]-1 , v = it[1]-1;
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        return adj;
    }
    vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int n, int k){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        dist[k-1] = 0;
        pq.push({0,k-1});
        while(!pq.empty()) {
            auto [dis,u] = pq.top();
            pq.pop();
            for (auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;
                if (dis + wt < dist[v]) {
                    dist[v] = dis + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
public:
    int networkDelayTime(vector<vector<int>>& arr, int n, int k) {
        auto adj = buildAdj(n,arr);
        auto dist = dijkstra(adj,n,k);
        int maxi = -1;
        for (int d : dist) {
            if (d == 1e9) return -1;
            maxi = max(maxi, d);
        }
        return maxi;
    }
};
