class Solution {
public:
    string encode(vector<string>& arr) {
        string s;
        for(string str : arr) {
            s+=to_string(str.size())+"#"+str;
        }
        return s;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> ans;
        int i = 0;
        while(i < n) {
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i,j-i));
            string str = s.substr(j+1,len);
            ans.push_back(str);
            i = j+1+len;
        }
        return ans;
    }
};
