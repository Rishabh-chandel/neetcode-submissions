class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int xori = 0;
        for(int it : arr) {
            xori ^= it;
        }
        return xori;
    }
};
