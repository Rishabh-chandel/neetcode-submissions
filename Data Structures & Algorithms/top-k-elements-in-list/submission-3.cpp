class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        multimap<int,int> mpcnt;
        for(auto it :mp) {
            mpcnt.insert({it.second,it.first});
            //cout<<it.first<<" "<<it.second<<endl;
        }
        vector<int> temp;
        for(auto it = mpcnt.begin(); it != mpcnt.end();it++ ) {
            int val = it->second;
            int key = it->first;
            temp.push_back(val);
            //cout<<it->first<<" "<<it->second<<endl;
        }
        for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
        for(int i=0;i<k;i++) {
            ans.push_back(temp[temp.size()-1-i]);
        }
        return ans;
    }
};
