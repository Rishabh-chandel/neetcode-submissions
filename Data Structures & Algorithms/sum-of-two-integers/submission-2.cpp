class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0 , carry = 0 , mask = 0xFFFFFFFF;;
        for(int i=0;i<32;i++) {
            int bit1 = (a>>i)&1 , bit2 = (b>>i)&1;
            int bit = bit1^bit2^carry;
            carry = (bit1+bit2+carry) >= 2 ? 1 : 0;
            if(bit) {
                ans |= (1<<i);
            }
        }
        // if (ans > 0x7FFFFFFF) {
        //     ans = ~(ans ^ mask);
        // }
        return ans;
    }
};
