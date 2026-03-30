class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        vector<pair<int,int>>temp;
        for(int i = 0; i < nums.size(); i++){
            temp.push_back(make_pair(nums[i],i));
        }
        sort(temp.begin(),temp.end());

        int strt = 0, end = temp.size() - 1;

        while(strt < end){
            if(temp[strt].first + temp[end].first == target){
                ans.push_back(min(temp[strt].second,temp[end].second));
                ans.push_back(max(temp[strt].second,temp[end].second));
                return ans;
            }else if(temp[strt].first + temp[end].first < target){
                strt++;
            }else{
                end--;
            }
        }
        return {};
    }
};
