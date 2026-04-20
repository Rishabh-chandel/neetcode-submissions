class Twitter {
private:
    int cnt;
    map<int,set<int>> mp;
    map<int,vector<pair<int,int>>> post;
public:
    Twitter() {
        cnt = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({cnt,tweetId});
        cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto it : post[userId]) {
            pq.push(it);
        }
        for(auto it : mp[userId]) {
            for(auto it_ : post[it]) {
                pq.push(it_);
            }
        }
        int sz = 0;
        vector<int> ans;
        while(!pq.empty() && sz < 10) {
            auto tp = pq.top();
            pq.pop();
            ans.push_back(tp.second);
            sz++;
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
