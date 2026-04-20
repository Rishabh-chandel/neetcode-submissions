class Solution {
public:
    bool hasDuplicate(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
            if(mp[arr[i]] > 1) return true;
        }
        return false;
    }
};
