class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = size(arr1);
        int m = size(arr2);
        if(n > m) return findMedianSortedArrays(arr2,arr1);
        int low = 0 , high = n;
        int lele = (n+m+1)/2;
        while(low <= high) {
            int mid1 = (low+high)/2;
            int mid2 = lele-mid1;
            int l1 = -1e9 , r1 = 1e9;
            int l2 = -1e9 , r2 = 1e9;
            if(mid1 < n) r1 = arr1[mid1];
            if(mid2 < m) r2 = arr2[mid2];
            if(mid1-1 >= 0) l1 = arr1[mid1-1];
            if(mid2-1 >= 0) l2 = arr2[mid2-1];
            if(l1 <= r2 && l2 <= r1) {
                if((n+m)%2 == 1) return (double)max(l1,l2);
                return ((double)(max(l1,l2)+min(r1,r2)))/2.0; 
            }
            else if(l1 > l2) high = mid1-1;
            else low = mid1+1;
        }
        return -1;
    }
};
