class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int it : arr) {
            pq.push(it);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
