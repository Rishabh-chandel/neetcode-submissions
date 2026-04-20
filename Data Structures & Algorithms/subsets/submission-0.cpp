class Solution {
private:
    vector<vector<int>> ans;
    int n;
    void f(int idx,vector<int>& curr,vector<int>& arr) {
        if(idx == n) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(arr[idx]);
        f(idx+1,curr,arr);
        curr.pop_back();
        f(idx+1,curr,arr);
    }
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        n = arr.size();
        vector<int> curr;
        f(0,curr,arr);
        return ans;
    }
};
