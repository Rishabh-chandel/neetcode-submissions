class Solution {
private:
    stack<int> st;
    vector<vector<int>> getAdj(int V,vector<vector<int>>& arr) {
        vector<vector<int>> adj(V);
        for(auto it : arr) {
            int u = it[0] , v = it[1];
            adj[v].push_back(u);
        }
        return adj;
    }
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it,adj,vis);
            }
        }
        st.push(node);
    }
public:
    bool canFinish(int V, vector<vector<int>>& arr) {
        vector<int> vis(V,0) , indeg(V,0);
        vector<vector<int>> adj = getAdj(V,arr);
        // for(int i=0;i<V;i++) {
        //     if(!vis[i]) {
        //         dfs(i,adj,vis);
        //     }
        // }
        vector<int> ans;
        // while(!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        for(int i=0;i<V;i++) {
            for(int it : adj[i]) {
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(indeg[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        if(ans.size() == V) return true;
        return false;
    }
};
