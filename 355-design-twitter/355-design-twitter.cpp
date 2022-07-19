class Twitter {
public:
    int count=0;
    map<int,pair<set<int>,vector<pair<int,int>>>> mp;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].first.insert(userId);
        mp[userId].second.push_back({count,tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto fs=mp[userId].first;
        vector<pair<int,int>> ans;
        for(auto &it:fs){
            auto tweets = mp[it].second;
            for(auto &it1:tweets)
                ans.push_back(it1);
        }
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        if(ans.size()>10)
        ans.resize(10);
        vector<int> temp;
        for(int i=0;i<ans.size();i++)
            temp.push_back(ans[i].second);
        return temp;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].first.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].first.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */