class Solution {
public:
    int leastInterval(vector<char>& arr, int n) {
        map<char,int> mp;
        for(char ch : arr) mp[ch-'A']++;
        priority_queue<int> pq;
        for(auto [ch,cnt] : mp) {
            pq.push(cnt);
        }
        int ans = 0;
        while(!pq.empty()) {
            vector<int> temp;
            for(int i=1;i<=n+1;i++) {
                if(!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int it : temp) {
                if(it > 0) pq.push(it);
            }
            if(pq.empty()) ans+=temp.size();
            else ans+=(n+1);
        }
        return ans;
    }
};
