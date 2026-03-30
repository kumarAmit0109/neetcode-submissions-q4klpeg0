class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        vector<int>sizes;
        for( string str : strs){
            sizes.push_back(str.size());
        }

        string res = "";
        for(int size: sizes){
            res += to_string(size)+',';
        }
        res += '#';

        for(string str: strs){
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        if( s.empty()){
            return {};
        }

        vector<int>sizes;
        
        int i = 0;
        while(s[i] != '#'){
            string temp = "";
            while(s[i]!=','){
                temp += s[i];
                i++;
            }

            sizes.push_back(stoi(temp));
            i++;
        }

        vector<string>ans;
        i++;

        for(int size : sizes){
            string temp;
            while(size--){
                temp += s[i];
                i++;
            }
            ans.push_back(temp);
        }
           
        return ans;

    }
};
