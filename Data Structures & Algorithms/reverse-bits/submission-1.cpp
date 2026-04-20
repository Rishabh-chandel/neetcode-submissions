class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int idx = 31;
        while(n) {
            ans+=((1<<idx)*(n&1));
            n>>=1;
            idx--;
        }
        return ans;
    }
};
