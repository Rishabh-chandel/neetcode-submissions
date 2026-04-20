class Solution {
private:
    int sq_sum(int n) {
        int sum = 0;
        while(n) {
            int rem = n%10;
            int sq = rem*rem;
            sum += sq;
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(!st.count(n)) {
            st.insert(n);
            n = sq_sum(n);
            if(n == 1) return 1;
        }
        return 0;
    }
};
