class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int i = 0 , j = 0;
        while(j < n) {
            if((j-i) > k) {
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            if(mp.count(arr[j])) return true;
            mp[arr[j]]++;
            j++;
        }
        return false;
    }
};