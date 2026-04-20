class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<int,vector<int>>> pq;
        for(auto it : arr) {
            int x = it[0] , y = it[1];
            int dis = ((x*x)+(y*y));
            pq.push({dis,{x,y}});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int x = it.second[0] , y = it.second[1];
            ans.push_back({x,y});
        }
        return ans;
    }
};
