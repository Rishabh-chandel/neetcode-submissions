class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
        int n = arr.size() , m = arr[0].size();
        map<int,set<char>> row , col;
        map<pair<int,int>,set<char>> mp;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j] == '.') continue;
                pair<int,int> pr = {i/3,j/3};
                if(row[i].count(arr[i][j]) || col[j].count(arr[i][j]) || mp[pr].count(arr[i][j]))
                    return false;
                mp[pr].insert(arr[i][j]);
                row[i].insert(arr[i][j]);
                col[j].insert(arr[i][j]);
            }
        }
        return true;
    }
};
