class disjointSet {
public:
    vector<int> rank,parent,size;
public:
    disjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }
    void UnoinByRank(int u,int v) {
        int ulpar_u =findUParent(u);
        int ulpar_v = findUParent(v);
        if(ulpar_u == ulpar_v) return;
        if(rank[ulpar_u] < rank[ulpar_v]){
            parent[ulpar_u] = ulpar_v;
        }
        else if(rank[ulpar_u] > rank[ulpar_v]) {
            parent[ulpar_v] = ulpar_u;
        }
        else {
            parent[ulpar_v] = ulpar_u;
            rank[ulpar_u]++;
        }
    }
    void UnoinBySize(int u,int v) {
        int ulpar_u =findUParent(u);
        int ulpar_v = findUParent(v);
        if(ulpar_u == ulpar_v) return;
        if(size[ulpar_u] < size[ulpar_v]){
            parent[ulpar_u] = ulpar_v;
            size[ulpar_v] += size[ulpar_u];
        }
        else {
            parent[ulpar_v] = ulpar_u;
            size[ulpar_u] += size[ulpar_v];
        }
    }
};

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
public:
    vector<int> findRedundantConnection(vector<vector<int>>& arr) {
        int n = arr.size();
        disjointSet ds(1001);
        for(auto it : arr) {
            int u = it[0] , v = it[1];
            if(ds.findUParent(u) != ds.findUParent(v)) {
                ds.UnoinBySize(u,v);
            }
            else return it;
        }
        return {};
    }
};
