class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        int n = arr.size();
        int st = 0 , ed = n-1;
        while(st < ed) {
            int sum = arr[st]+arr[ed];
            if(sum == k) return {st+1,ed+1};
            else if(sum > k) ed--;
            else st++;
        }
        return {-1,-1};
    }
};
