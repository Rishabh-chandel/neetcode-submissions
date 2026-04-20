class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) {
            int curr = arr[i];
            int rem = target - curr;
            if(mp.count(rem)) {
                return {mp[rem] , i};
            }
            mp[curr] = i;
        }
        return {-1,-1};
    }
};
