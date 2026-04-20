class Solution {
private:
    int n;
    vector<string> ans;
    bool isValid(string s) {
        int cnt = 0;
        for(char ch : s) {
            if(cnt < 0) return false;
            if(ch == '(') cnt++;
            else cnt--;
        }
        return cnt == 0;
    }
    void f(string& curr) {
        if(curr.size() == 2*n) {
            if(isValid(curr)) ans.push_back(curr);
            return;
        }
        curr+='(';
        f(curr);
        curr.pop_back();
        curr+=')';
        f(curr);
        curr.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        string curr = "";
        f(curr);
        return ans;
    }
};
