class Solution {
private:
    void bfs(int u,int v,vector<vector<char>>& arr,vector<vector<int>>& vis) {
        int n = arr.size() , m = arr[0].size();
        queue<pair<int,int>> q;
        q.push({u,v});
        vis[u][v] = 1;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            for(auto [dr,dc] : dir) {
                int nr = r+dr , nc = c+dc;
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && arr[nr][nc] == '1') {
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                } 
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && arr[i][j] == '1') {
                    cnt++;
                    bfs(i,j,arr,vis);
                }
            }
        }
        return cnt;
    }
};
