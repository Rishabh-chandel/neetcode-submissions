class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int i = m-1 , j = n-1;
        int idx = m+n-1;
        while(i >= 0 && j >= 0) {
            if(arr1[i] > arr2[j]) {
                arr1[idx--] = arr1[i--];
            }
            else arr1[idx--] = arr2[j--];
        }
        while(i >= 0) {
            arr1[idx--] = arr1[i--];
        }
        while(j >= 0) {
            arr1[idx--] = arr2[j--];
        }
    }
};