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
    vector<vector<int>> getAdj(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> adj;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int dis = abs(arr[i][0]-arr[j][0]) + 
                          abs(arr[i][1]-arr[j][1]);
                adj.push_back({dis,i,j});
            }
        }
        return adj;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> adj = getAdj(arr);
        disjointSet ds(n+1);
        sort(adj.begin(),adj.end());
        int sum = 0;
        for(auto it : adj) {
            int dis = it[0] , u = it[1] , v = it[2];
            if(ds.findUParent(u) != ds.findUParent(v)) {
                sum+=dis;
                ds.UnoinBySize(u,v);
            }
        }
        return sum;
    }
};
