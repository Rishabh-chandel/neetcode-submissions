class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string,vector<string>> mp;
        for(string& str : arr) {
            string s_str = str;
            sort(s_str.begin(),s_str.end());
            mp[s_str].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
