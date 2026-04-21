class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr) {
        int n = arr.size();
        int sumi = 0;
        int mini = n;
        int i = 0 , j = 0;
        int sum = 0;
        while(j < n) {
            sumi += arr[j];
            sum+=arr[j];
            while(sum >= k) {
                mini = min(mini,j-i+1);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        if(sumi < k) return 0;
        return mini;
    }
};