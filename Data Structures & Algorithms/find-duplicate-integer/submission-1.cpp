class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for(int num : arr) {
            int idx = abs(num)-1;
            if(arr[idx] < 0) {
                return abs(num);
            }
            arr[idx]*=-1;
        }
        return -1;
    }
};
