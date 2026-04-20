class Twitter {
private:
    int cnt;
    unordered_map<int,unordered_set<int>> mp;
    unordered_map<int,vector<pair<int,int>>> post;
public:
    Twitter() {
        cnt = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({cnt,tweetId});
        cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        mp[userId].insert(userId);
        for(auto it : mp[userId]) {
            if(post[it].empty()) continue;
            int idx = post[it].size()-1;
            int tm = post[it][idx].first , id = post[it][idx].second;
            pq.push({tm,id,it,idx});
        }
        vector<int> ans;
        while(!pq.empty() && ans.size() < 10) {
            auto it = pq.top(); pq.pop();
            int tm = it[0] , id = it[1] , uid = it[2] , idx = it[3];
            ans.push_back(id);
            if(idx > 0) pq.push({post[uid][idx-1].first,post[uid][idx-1].second,uid,idx-1});
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
           mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
