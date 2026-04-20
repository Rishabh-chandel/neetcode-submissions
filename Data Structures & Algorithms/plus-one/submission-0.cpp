class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int n = arr.size();
        int carry = 1;
        for(int i=n-1;i>=0;i--) {
            int sum = (arr[i]+carry)%10;
            carry = (arr[i]+carry)/10;
            arr[i] = sum;
        }
        if(carry) arr.insert(arr.begin(), carry);
        return arr;
    }
};
