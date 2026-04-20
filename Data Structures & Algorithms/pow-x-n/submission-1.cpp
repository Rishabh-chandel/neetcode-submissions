class Solution {
private:
    double powcal(double x, long long n) {
        double res = 1.0;
        while (n > 0) {
            if (n & 1) res *= x;
            x = x * x;   
            n >>= 1;
        }
        return res;
    }
public:
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1/x;
            n = -n;
        }
        return powcal(x,n);
    }
};
