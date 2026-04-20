class Solution {
private:
    bool isAnagram(string s, string t) {
        int n = s.size() , m = t.size();
        vector<int> hash1(26,0) , hash2(26,0);
        for(char ch : s) {
            int idx = ch - 'a';
            hash1[idx]++;
        }
        for(char ch : t) {
            int idx = ch - 'a';
            hash2[idx]++;
        }
        for(int i=0;i<26;i++) {
            if(hash1[i] != hash2[i]) return 0;
        }
        return 1;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        int n = arr.size();
        vector<vector<string>> ans;
        for(int i=0;i<n;i++) {
            string s = arr[i];
            vector<string> curr;
            curr.push_back(s);
            if(s == "AB") continue;
            for(int j=0;j<n;j++) {
                string t = arr[j];
                if(t == "AB") continue;
                if(i != j) {
                    if(isAnagram(s,t)) {
                        curr.push_back(t);
                        arr[j] = "AB";
                    }
                }
            }
            ans.push_back(curr);
            arr[i] = "AB";
        }
        return ans;
    }
};
