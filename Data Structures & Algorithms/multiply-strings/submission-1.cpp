class Solution {
public:
    string mul(string s, char d, int zero) {
        // start from the last digit of string number
        int i = s.size() - 1;
        // carry generated during multiplication
        int carry = 0;
        // convert the character digit to integer
        // example: '5' -> 5
        int digit = d - '0';
        // this string will store the multiplication result
        string cur;
        // continue while digits are left OR carry still exists
        while (i >= 0 || carry) {
            // if digits are left take them, otherwise use 0
            int n = (i >= 0) ? s[i] - '0' : 0;
            // multiply digit and add carry
            int prod = n * digit + carry;
            // store the last digit of product
            // example: 17 -> store '7'
            cur.push_back((prod % 10) + '0');
            // update carry
            // example: 17 -> carry = 1
            carry = prod / 10;
            // move to next digit on left
            i--;
        }
        // digits were added in reverse order
        // so we reverse the string to correct it
        reverse(cur.begin(), cur.end());
        // append zeros according to place value
        // example: if zero = 2 -> add "00"
        return cur + string(zero, '0');
    }

    string add(string num1, string num2) {
        // start from the last digits of both numbers
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        // carry generated during addition
        int carry = 0;
        // this string will store the addition result
        string res;
        // continue while digits exist in either number OR carry exists
        while (i >= 0 || j >= 0 || carry) {
            // take digit from num1 if available
            int n1 = (i >= 0) ? num1[i] - '0' : 0;
            // take digit from num2 if available
            int n2 = (j >= 0) ? num2[j] - '0' : 0;
            // add digits and carry
            int total = n1 + n2 + carry;
            // store last digit of result
            // example: 14 -> store '4'
            res.push_back((total % 10) + '0');
            // update carry
            // example: 14 -> carry = 1
            carry = total / 10;
            // move left in both numbers
            i--;
            j--;
        }
        // digits were stored in reverse order
        // so reverse the result to correct it
        reverse(res.begin(), res.end());
        // return final addition result
        return res;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        if (num1.size() < num2.size()) {
            return multiply(num2, num1);
        }

        string res = "";
        int zero = 0;
        for (int i = num2.size() - 1; i >= 0; --i) {
            // multiply the elements of num1 by each element of num2 one by one
            // and add them just like the traditional multiplication
            string cur = mul(num1, num2[i], zero);
            res = add(res, cur);
            zero++;
        }

        return res;
    }

    
};