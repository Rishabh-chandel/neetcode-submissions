class Solution {
private:
    vector<vector<int>> buildAdj(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n);
        for(auto it : arr) {
            int u = it[0] , v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    bool dfs(int u,int v,unordered_map<int,vector<int>>& adj,vector<int>& vis) {
        vis[u] = 1;
        if(u == v) return 1;
        for(auto adjnode : adj[u]) {
            if(!vis[adjnode]) 
                if(dfs(adjnode,v,adj,vis)) return 1;
        }
        return 0;
    } 
public:
    vector<int> findRedundantConnection(vector<vector<int>>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++) {
            int u = arr[i][0] , v = arr[i][1];
            vector<int> vis(1001,0);
            if(adj.count(u) && adj.count(v) && dfs(u,v,adj,vis)) 
                return arr[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
