class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& arr) {
        int n = intv.size() , m = arr.size();
        vector<vector<int>> ans;
        int mini = 10001 , maxi = -1;
        int i = 0;
        while(i < n) {
            int st = intv[i][0] , ed = intv[i][1];
            if(ed < arr[0]) ans.push_back({st,ed});
            else break;
            i++;
        }
        while(i < n) {
            if(intv[i][0] > arr[1]) break;
            arr[0] = min(arr[0],intv[i][0]);
            arr[1] = max(arr[1],intv[i][1]);
            i++;
        }
        ans.push_back(arr);
        while(i < n) {
            ans.push_back(intv[i]);
            i++;
        }
        return ans;
    }
};
