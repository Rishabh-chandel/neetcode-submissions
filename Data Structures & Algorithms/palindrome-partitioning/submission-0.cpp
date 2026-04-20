class Solution {
private:
    vector<vector<string>> ans;
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0 , r = n-1;
        while(l < r) {
            if(s[l] != s[r]) return 0;
            l++ , r--;
        }
        return 1;
    }
    void f(int idx,vector<string>& curr,string s) {
        if(idx == s.size()) {
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<s.size();i++) {
            string subs = s.substr(idx,i-idx+1);
            if(isPalindrome(subs)) {
                curr.push_back(s.substr(idx,i-idx+1));
                f(i+1,curr,s);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> path;
        f(0,path,s);
        return ans;
    }
};
