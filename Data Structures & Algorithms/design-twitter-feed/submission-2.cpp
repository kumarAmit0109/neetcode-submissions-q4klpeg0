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
        tweetMap[userId].push_back({time, tweetId}); 
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        // Comparator for heap
        // We want the tweet with LARGEST time at top
        auto compare = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        };

        // Heap will store:
        // {time, tweetId, userId, index_in_user_tweet_list}
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);
        // user should also see their own tweets
        followMap[userId].insert(userId);
        // Push latest tweet of each followed user into heap
        for (int followeeId : followMap[userId]) {
            // if user has tweets
            if (tweetMap.count(followeeId)) {
                const vector<pair<int,int>>& tweets = tweetMap[followeeId];
                // index of latest tweet
                int index = tweets.size() - 1;
                // push newest tweet into heap
                minHeap.push({
                    tweets[index].first,   // time
                    tweets[index].second,  // tweetId
                    followeeId,
                    index
                });
            }
        }
        // Extract the 10 most recent tweets
        while (!minHeap.empty() && res.size() < 10) {
            // get most recent tweet
            vector<int> curr = minHeap.top();
            minHeap.pop();
            // add tweetId to result
            res.push_back(curr[1]);
            int user = curr[2];
            int index = curr[3];
            // check if older tweet exists from same user
            if (index > 0) {
                const pair<int,int>& tweet = tweetMap[user][index - 1];
                // push older tweet into heap
                minHeap.push({
                    tweet.first,     // time
                    tweet.second,    // tweetId
                    user,
                    index - 1
                });
            }
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
