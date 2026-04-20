class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int m = arr.size() , n = arr[0].size();
        vector<int> ans;
        int st = 0 , ed = n-1;
        int top = 0 , bottom = m-1;
        while(st <= ed && top <= bottom) {
            for(int i=st;i<=ed;i++) {
                ans.push_back(arr[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++) {
                ans.push_back(arr[i][ed]);
            }
            ed--;
            if(top <= bottom) {
                for(int i=ed;i>=st;i--) {
                    ans.push_back(arr[bottom][i]);
                }
                bottom--;
            }
            if(st <= ed) {
                for(int i=bottom;i>=top;i--) {
                    ans.push_back(arr[i][st]);
                }
                st++;
            }
        }
        return ans;
    }
};
