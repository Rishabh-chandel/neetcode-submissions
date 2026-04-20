class Solution {
private:
    double powcal(double x, int n) {
        if(n == 0) return 1.0;
        double half = myPow(x,n/2);
        double res = half * half;
        if(n%2 == 1) res *= x;
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
