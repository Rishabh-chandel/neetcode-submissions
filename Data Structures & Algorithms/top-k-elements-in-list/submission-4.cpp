class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        map<int,int> mp;
        for(int num : arr) {
            mp[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto [num,cnt] : mp) {
            pq.push({cnt,num});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
