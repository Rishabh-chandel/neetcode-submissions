class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& nin) {
        int n = arr.size();
        vector<vector<int>> ans;
        int i = 0;
        while(i < n && arr[i][1] < nin[0]) {
            ans.push_back(arr[i]);
            i++;
        }
        while(i < n && arr[i][0] <= nin[1]) {
            nin[0] = min(nin[0],arr[i][0]);
            nin[1] = max(nin[1],arr[i][1]);
            i++;
        }
        ans.push_back(nin);
        while(i < n) {
            ans.push_back(arr[i]);
            i++;
        }
        return ans;
    }
};
