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
    void dfs(int src,vector<vector<int>>& adj,vector<int>& vis) {
        vis[src] = 1;
        for(auto it : adj[src]) {
            if(!vis[it]) {
                dfs(it,adj,vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj = buildAdj(n,arr);
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};
