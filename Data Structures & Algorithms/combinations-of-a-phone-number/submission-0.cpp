class Solution {
private:
    vector<string> ans;
    void f(int idx,string curr,string s,map<char,string>& mp) {
        if(idx == s.size()) {
            ans.push_back(curr);
            return;
        }
        f(idx+1,curr+mp[s[idx]][0],s,mp);
        f(idx+1,curr+mp[s[idx]][1],s,mp);
        f(idx+1,curr+mp[s[idx]][2],s,mp);
        if(mp[s[idx]].size() == 4) f(idx+1,curr+mp[s[idx]][3],s,mp);
    }
public:
    vector<string> letterCombinations(string s) {
        int n = s.size();
        if(n == 0) return {};
        string curr;
        map<char,string> mp= {{'2',"abc"},{'3',"def"},{'4',"ghi"},
        {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        f(0,curr,s,mp);
        return ans;
    }
};
