class Solution {
private:
    int n , m;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int bfs(vector<vector<int>>& arr,vector<vector<int>>& vis) {
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j] == 2) {
                    q.push({i,{j,0}});
                    vis[i][j] = 2;
                }
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first , c = it.second.first;
            int tm = it.second.second;
            cnt = max(cnt,tm);
            for(auto [dr,dc] : dir) {
                int nr = r+dr , nc = c+dc;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && arr[nr][nc] == 1 && !vis[nr][nc]) {
                    q.push({nr,{nc,tm+1}});
                    vis[nr][nc] = 2;
                }
            }
        }
        return cnt;
    }
public:
    int orangesRotting(vector<vector<int>>& arr) {
        n = arr.size() , m = arr[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = bfs(arr,vis);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j] == 1 && vis[i][j] == 0) 
                    return -1;
            }
        }
        return cnt;
    }
};
