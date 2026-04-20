class Solution {
private:
    int n;
    vector<vector<int>> ans;
    void f(int idx,vector<int>& curr,vector<int>& arr) {
        if(idx == n) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(arr[idx]);
        f(idx+1,curr,arr);
        curr.pop_back();
        while(idx+1 < arr.size() && arr[idx+1] == arr[idx]) idx++;
        f(idx+1,curr,arr);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        n = arr.size();
        vector<int> curr;
        sort(arr.begin(),arr.end());
        f(0,curr,arr);
        return ans;
    }
};
