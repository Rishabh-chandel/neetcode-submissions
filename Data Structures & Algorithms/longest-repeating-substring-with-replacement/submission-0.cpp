class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> hash(26,0);
        int i = 0 , j = 0;
        int ans = 0 , maxi = 0;
        while(j < n) {
            hash[s[j]-'A']++;
            maxi = max(maxi,hash[s[j]-'A']);
            if((j-i+1)-maxi > k) {
                hash[s[i++]-'A']--;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
