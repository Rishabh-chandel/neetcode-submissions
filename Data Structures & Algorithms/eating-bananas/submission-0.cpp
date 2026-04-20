class Solution {
private:
    int f(vector<int>& arr,int mid) {
        int n = arr.size();
        int count = 0;
        for(int i=0;i<n;i++) {
            count+=(ceil(double(arr[i])/double(mid)));
        }
        return count;
    }
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int low = 1;
        int high = *max_element(arr.begin(),arr.end());
        while(low <= high) {
            int mid = (low+high)/2;
            if(f(arr,mid) > h) low = mid+1; 
            else high = mid-1;
        }
        return low;
    }
};
