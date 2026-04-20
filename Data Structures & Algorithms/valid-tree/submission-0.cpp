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
    bool detectCycle(int src,vector<vector<int>>& adj,vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()) {
            auto [node,parent] = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    q.push({it,node});
                    vis[it] = 1;
                }
                else if(it != parent) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj = buildAdj(n,arr);
        vector<int> vis(n,0);
        if(detectCycle(0,adj,vis)) return false;
        for(int i=0;i<n;i++) {
            if(!vis[i]) return false;
        }
        return true;
    }
};
