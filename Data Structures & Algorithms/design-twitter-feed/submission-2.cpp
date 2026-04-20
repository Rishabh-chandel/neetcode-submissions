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
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it : post[userId]) {
            if(pq.size() < 10)
                pq.push(it);
            else if(it.first > pq.top().first) {
                pq.pop();
                pq.push(it);
            }
        }
        for(auto followee : mp[userId]) {
            for(auto tweet : post[followee]) {
                if(pq.size() < 10)
                    pq.push(tweet);
                else if(tweet.first > pq.top().first) {
                    pq.pop();
                    pq.push(tweet);
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end()); 
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
