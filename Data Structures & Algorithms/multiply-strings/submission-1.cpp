class Solution {
public:
    string multiply(string num1, string num2) {
        long long no1 = stoi(num1);
        long long no2 = stoi(num2);
        string ans = to_string(no1*no2);
        return ans;
    }
};
