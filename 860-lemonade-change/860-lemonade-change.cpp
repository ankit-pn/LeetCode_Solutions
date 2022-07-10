class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        for(auto &it:bills){
            mp[it]++;
            int rem=it-5;
            if(rem==5){
              if(mp[5]>=1)
                  mp[5]--;
                else
                    return 0;
            }
            if(rem==10){
                    if(mp[10]>=1)
                        mp[10]--;
                    else if(mp[5]>=2)
                        mp[5]-=2;
                    else
                        return 0;
            }            
            if(rem==15){
                if(mp[10]>=1 && mp[5]>=1)
                    mp[10]--,mp[5]--;
                else if(mp[5]>=3)
                    mp[5]-=3;
                else
                    return 0;
            }
        }
        return 1 ;
    }
};