class Solution {
public:
    unordered_map<int,int> mp;
    int longestConsecutive(vector<int>& nums) {
        // first algo by hashing.
        // idea is simple in all cases, just check for x-1 if x-1 not present then begin search, if x-1 present , there is not need to search.
        
        // creating map.
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        int ans=0;
        for(auto &it:mp){
            int p = it.first;
            if(mp.find(p-1)==mp.end()){
                int y=p+1;
                while(mp.find(y)!=mp.end()){
                    y++;
                }
                ans=max(ans,y-p);
            }
        }
        return ans;
        
        
        
    }
};