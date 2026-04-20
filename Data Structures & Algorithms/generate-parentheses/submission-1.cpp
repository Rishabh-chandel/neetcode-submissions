class Solution {
private:
    int n;
    vector<string> ans;
    void f(int open,int close, string& curr) {
        if(curr.size() == 2*n) {
            ans.push_back(curr);
            return;
        }
        if(open < n) {
            curr+='(';
            f(open+1,close,curr);
            curr.pop_back();
        }
        if(close < open && close < n) {
            curr+=')';
            f(open,close+1,curr);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        string curr = "";
        int open = 0 , close = 0;
        f(open,close,curr);
        return ans;
    }
};
