class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int sum_arr = 0 , sum_num = 0;
        for(int i=0;i<=n;i++) sum_num+=i;
        for(int it : arr) sum_arr+=it;
        return abs(sum_arr-sum_num);
    }
};
