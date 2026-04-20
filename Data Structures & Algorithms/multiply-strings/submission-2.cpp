class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n = num1.size() , m = num2.size();
        vector<int> temp((n+m),0);
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                int no1 = num1[i]-'0' , no2 = num2[j]-'0';
                int ind = i+j+1;
                int sum = (no1*no2)+temp[ind];
                int mul = sum%10;
                int rem = sum/10;
                temp[ind] = sum % 10;
                temp[ind-1] += rem;
            }
        }
        string ans = "";
        int idx = 0;
        while(idx < n+m && temp[idx] == 0) idx++;
        while(idx < n+m) {
            ans+=(temp[idx]+'0');
            idx++;
        }
        return ans;
    }
};
