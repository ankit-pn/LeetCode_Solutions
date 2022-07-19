class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.first>b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto &it:nums)
            mp[it]++;
        vector<pair<int,int>> p;
        for(auto &it:mp)
            p.push_back({it.second,it.first});
        sort(p.begin(),p.end(),cmp);
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(p[i].second);
        return ans;
    }
};