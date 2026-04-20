class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            int rem = k-arr[i];
            if(mp.count(rem)) return {mp[rem],i};
            mp[arr[i]] = i;
        }
        return {-1,-1};
    }
};
