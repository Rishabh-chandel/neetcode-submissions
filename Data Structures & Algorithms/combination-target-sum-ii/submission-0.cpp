class Solution {
private:
    int n;
    vector<vector<int>> ans;
    void f(int idx,int sum,vector<int>& curr,vector<int>& arr) {
        if(idx == n) {
            if(sum == 0) ans.push_back(curr);
            return;
        }
        curr.push_back(arr[idx]);
        if(sum >= arr[idx]) f(idx+1,sum-arr[idx],curr,arr);
        curr.pop_back();
        while(idx+1 < n && arr[idx+1] == arr[idx]) idx++;
        f(idx+1,sum,curr,arr);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> curr;
        sort(arr.begin(),arr.end());
        f(0,k,curr,arr);
        return ans;
    }
};
