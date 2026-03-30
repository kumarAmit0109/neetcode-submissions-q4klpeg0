class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string binary = "";
        // convert it into binary
        // extract the bit and if bit is set then add it to the string
        for(int i = 0; i < 32; i++){
            if(n & (1 << i)){
                binary += '1';
            }else{
                binary += '0';
            }
        }

        // now reverse the binary
        uint32_t res = 0;
        for(int i = 0; i < 32; i++){
            if(binary[31 - i] == '1'){
                res |= (1 << i);
            }
        }

        return res;
    }
};
