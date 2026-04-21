class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int,int>> dif(n);
        for(int i=0;i<n;i++) {
            dif[i] = {abs(arr[i]-x),arr[i]};
        }
        sort(dif.begin(),dif.end());
        vector<int> ans;
        for(int i=0;i<k;i++) ans.push_back(dif[i].second);
        sort(ans.begin(),ans.end());
        return ans;
    }
};