class Solution {
private:
    int f(int idx,int sum,vector<int>& arr,int k) {
        if(idx < 0) {
            if(k == sum) return 1;
            return 0; 
        }
        int add = f(idx-1,sum+arr[idx],arr,k);
        int sub = f(idx-1,sum-arr[idx],arr,k);
        return add+sub;
    }
public:
    int findTargetSumWays(vector<int>& arr, int k) {
        return f(arr.size() - 1, 0, arr, k);
    }
};