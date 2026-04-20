class Solution {
private:
    static bool comp(pair<int,int> &p1, pair<int,int> &p2) {
        return p1.first < p2.first; 
    }

public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> hash(26, {INT_MAX, INT_MIN});
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            hash[idx].first = min(hash[idx].first, i);
            hash[idx].second = max(hash[idx].second, i);
        }
        vector<pair<int,int>> intervals;
        for(auto &p : hash) {
            if(p.first != INT_MAX) {
                intervals.push_back(p);
            }
        }

        sort(intervals.begin(), intervals.end(), comp);
        vector<pair<int,int>> merged;
        merged.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].first <= merged.back().second) {
                merged.back().second = max(merged.back().second, intervals[i].second);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        vector<int> ans;
        for(auto &p : merged) {
            ans.push_back(p.second - p.first + 1);
        }
        return ans;
    }
};