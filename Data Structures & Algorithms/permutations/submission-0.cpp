class Solution {
private:
    int n;
    vector<vector<int>> ans;
    void f(int idx,vector<int>& curr,vector<int>& hash,vector<int>& arr) {
        if(idx == n) {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++) {
            if(!hash[i]) {
                curr[idx] = arr[i];
                hash[i] = 1;
                f(idx+1,curr,hash,arr);
                hash[i] = 0;
                curr[idx] = -1;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& arr) {
        n = arr.size();
        vector<int> curr(n,-1) , hash(n);
        f(0,curr,hash,arr);
        return ans;
    }
};
