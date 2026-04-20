class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int> pq;
        for(int it : arr) pq.push(it);
        while(pq.size() > 1) {
            int fst = pq.top(); pq.pop();
            int sec = pq.top(); pq.pop();
            int rem = 0;
            if(fst == sec) continue;
            else rem = max(fst,sec)-min(fst,sec);
            pq.push(rem);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
