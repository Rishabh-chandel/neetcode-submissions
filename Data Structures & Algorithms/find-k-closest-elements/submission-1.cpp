class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int i = 0 , j = n-1;
        while((j-i) >= k) {
            if(abs(arr[i]-x) <= abs(arr[j]-x)) 
                j--;
            else i++;
        }
        return vector<int>(arr.begin() + i, arr.begin() + j + 1);
    }
};