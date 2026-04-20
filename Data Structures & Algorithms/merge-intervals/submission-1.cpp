class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++) {
            int st = arr[i][0] , ed = arr[i][1];
            if(!ans.empty() && ed <= ans.back()[1]) continue;
            for(int j=i+1;j<n;j++) {
                if(ed >= arr[j][0]) ed = max(ed,arr[j][1]);
            }
            ans.push_back({st,ed});
        }
        return ans;
    }
};
