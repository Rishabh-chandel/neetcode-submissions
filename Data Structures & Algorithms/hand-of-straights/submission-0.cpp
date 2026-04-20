class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int sz) {
        int n = arr.size();
        map<int,int> mp;
        for(int it : arr) mp[it]++;
        sort(arr.begin(),arr.end());
        for(int num : arr) {
            if(mp[num] > 0) {
                for(int i=num;i<num+sz;i++) {
                    if(mp[i] == 0) return 0;
                    mp[i]--;
                }
            }
        }
        return 1;
    }
};
