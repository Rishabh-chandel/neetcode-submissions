class Solution {
private:
    double powcal(double x, int n) {
        double res = 1.0;
        while(n) {
            if(n%2) res*=x;
            x = x * x;
            n/=2;
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
