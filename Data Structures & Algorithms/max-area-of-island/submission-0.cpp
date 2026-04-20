class Solution {
private:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int bfs(int u,int v,vector<vector<int>>& arr,vector<vector<int>>& vis) {
        int n = arr.size() , m = arr[0].size();
        queue<pair<int,int>> q;
        q.push({u,v});
        vis[u][v] = 1;
        int cnt = 1;
        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            for(auto [dr,dc] : dir) {
                int nr = r+dr , nc = c+dc;
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && arr[nr][nc] == 1) {
                    cnt++;
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                } 
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxi = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && arr[i][j] == 1) {
                    maxi = max(maxi,bfs(i,j,arr,vis));
                    bfs(i,j,arr,vis);
                }
            }
        }
        return maxi;
    }
};
