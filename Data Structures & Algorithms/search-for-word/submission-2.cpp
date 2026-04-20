class Solution {
private:
    bool isValid(int i,int j,int n,int m) {
        return i < n && i >= 0 && j < m && j >= 0;
    }
    bool dfs(int i,int j,int idx,vector<vector<char>>& arr,string& s) {
        int n = arr.size() , m = arr[0].size();
        if(idx >= s.size()) return true;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        char ch = arr[i][j];
        arr[i][j] = '#';
        for(auto [di,dj] : dir) {
            int ni = i+di , nj = j+dj;
            if(isValid(ni,nj,n,m) && arr[ni][nj] == s[idx]) {
                if(dfs(ni,nj,idx+1,arr,s)) {
                    arr[ni][nj] = ch;
                    return true;
                }
            }
        }
        arr[i][j] = ch;
        return false;
    }
public:
    bool exist(vector<vector<char>>& arr, string s) {
        int n = arr.size() , m = arr[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j] == s[0]) {
                    if(dfs(i,j,1,arr,s)) return true;
                }
            }
        }
        return false;
    }
};
