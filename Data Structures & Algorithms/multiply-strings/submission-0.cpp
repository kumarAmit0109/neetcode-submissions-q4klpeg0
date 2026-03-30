class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        // max result length could be num1 + num2
        vector<int> res(num1.length() + num2.length(), 0);
        // reverse the strings first to make traversal easy
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i1 = 0; i1 < num1.length(); i1++){
            for (int i2 = 0; i2 < num2.length(); i2++){

                int prod = (num1[i1] - '0') * (num2[i2] - '0');
                // inititally res[i1 + i2] stores the current carry if there is any
                int sum = res[i1 + i2] + prod;
                // res[i1 + i2 + 1] it stores the carry for next operatioin
                res[i1 + i2 + 1] += sum / 10;
                res[i1 + i2] = sum %10;
            }
        }
        
        string result = "";
        int i = res.size() - 1;

        // skip leading zeros
        while (i >= 0 && res[i] == 0) {
            i--;
        }

        // build the string
        while (i >= 0) {
            result += (res[i] + '0');
            i--;
        }

        return result;

    }
};
