class Solution {
public:
    int carFleet(int t, vector<int>& pos, vector<int>& sp) {
        int n = pos.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++) {
            arr.push_back({pos[i],sp[i]});
        }
        sort(arr.begin(),arr.end());
        double tm = (double)(t-arr[n-1].first)/arr[n-1].second;
        int ans = 1;
        for(int i=n-2;i>=0;i--) {
            double tm_ = (double)(t-arr[i].first)/arr[i].second;
            if(tm_ > tm) {
                ans++;
                tm = tm_;
            }
        }
        return ans;
    }
};
