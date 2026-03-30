class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>res;

        for(int q : queries){
            int tempLength = -1;
            // for every query just find the minimum interval length which 
            // contains the query q in it
            for(auto& interval : intervals){
                int left = interval[0], right = interval[1];
                if(left <= q && q <= right){
                    if(tempLength == -1 || (right - left + 1) < tempLength){
                        tempLength = right - left + 1;
                    }
                }
            }
            res.push_back(tempLength);

        }
        return res;
    }
};
