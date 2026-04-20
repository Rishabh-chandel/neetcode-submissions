class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int num : arr) {
            mp[num]++;
        }
        vector<vector<int>> freq(n+1);
        for(auto [num,cnt] : mp) {
            freq[cnt].push_back(num);
        }
        vector<int> ans;
        for(int i=n;i>=0;i--) {
            for(int num : freq[i]) {
                ans.push_back(num);
                if(ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
