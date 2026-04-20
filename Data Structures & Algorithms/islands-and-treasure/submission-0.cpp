class Solution {
private:
    int m , n;
    int INFD = INT_MAX;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>>& arr,vector<vector<int>>& vis) {
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first.first , c = it.first.second;
            int dis = it.second;
            for(auto [dr,dc] : dir) {
                int nr = r+dr , nc = c+dc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && arr[nr][nc] == INFD && vis[nr][nc] == 0) {
                    vis[nr][nc] = dis + 1;
                    q.push({{nr,nc},dis+1});
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j] != -1 && arr[i][j] != 0 && vis[i][j] != 0) {
                    arr[i][j] = vis[i][j];
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& arr) {
        m = arr.size() , n = arr[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        bfs(arr,vis);
    }
};
