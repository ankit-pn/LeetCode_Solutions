class Solution {
public:
    int numRabbits(vector<int>& arr) {
        map<int,int> mp;
        int sum=0;
        for(auto &it:arr)
            mp[it]++;
        for(auto &it:mp)
            sum+=(it.first+1)*((it.second-1)/(it.first+1)+1);
        return sum;
    }
};