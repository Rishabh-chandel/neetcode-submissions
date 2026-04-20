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
        int slow = n , fast = sq_sum(n);
        while(slow != fast) {
            slow = sq_sum(slow);
            fast = sq_sum(fast);
            fast = sq_sum(fast);
        }
        return fast == 1;
    }
};
