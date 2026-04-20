class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = size(arr1);
        int m = size(arr2);
        if(n > m) return findMedianSortedArrays(arr2,arr1);
        vector<int> arr;
        for(int it : arr1) arr.push_back(it);
        for(int it : arr2) arr.push_back(it);
        sort(arr.begin(),arr.end());
        if((n+m)%2 == 1) return double(arr[(n+m)/2]);
        double m1 = arr[(n+m)/2-1] , m2 = arr[(n+m)/2];
        double ans = (m1+m2)/2;
        return ans;
    }
};
