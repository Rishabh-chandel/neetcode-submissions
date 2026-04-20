class Solution {
private:
    vector<vector<int>> getAdj(int V,vector<vector<int>>& arr) {
        vector<vector<int>> adj(V);
        for(auto it : arr) {
            int u = it[0] , v = it[1];
            adj[v].push_back(u);
        }
        return adj;
    }
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis, vector<int>& dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(!dfs(it, adj, vis, dfsVis))
                    return false;
            }
            else if(dfsVis[it]) {
                return false;   
            }
        }
        dfsVis[node] = 0;
        return true;
    }
public:
    bool canFinish(int V, vector<vector<int>>& arr) {
        vector<int> vis(V,0) , dfsVis(V,0);;
        vector<vector<int>> adj = getAdj(V,arr);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(!dfs(i, adj, vis, dfsVis))
                    return false;
            }
        }
        return true;
    }
};
