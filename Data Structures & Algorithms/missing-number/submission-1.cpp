class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int xor_num = 0 , xor_arr = 0;
        for(int i=0;i<=n;i++) xor_num^=i;
        for(int it : arr) xor_arr^=it;
        return xor_num^xor_arr;
    }
};
