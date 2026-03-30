class Twitter {
public:
    int time;
    // used to store who follow whom
    unordered_map<int, unordered_set<int>>followMap;
    // used to keep track of at which user post at what time which tweet
    // with the help of storing time we can easy send the recent 10 tweet
    // when getNewsFeed is called by simply extracting nd sorting wrt time
    unordered_map<int, vector<pair<int,int>>>tweetMap;
    // initialize time to zero
    Twitter():time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // first extract the tweet coresspondig to userId
        vector<pair<int,int>>feed = tweetMap[userId]; 
        // now add the followed user's tweet to the feed
        for(auto followeeId : followMap[userId]){
            // insert in end, the complete vector corresponding to the user with followeeId as userid
            feed.insert(feed.end(), tweetMap[followeeId].begin(), tweetMap[followeeId].end());
        }

        // sort in descending order to extract the recent 10 feed
        sort(feed.begin(),feed.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        vector<int>res;
        int n = min(10, (int)feed.size());
        for(int i = 0; i < n; i++){
            res.push_back(feed[i].second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // if follwer and followee are same then do nothing
        if(followerId != followeeId){
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
