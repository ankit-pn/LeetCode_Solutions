map<char,int> mp;
bool cmp(char &a,char &b){
        if(mp[a]==mp[b])
            return a>b;
         else
            return mp[a]>mp[b];
 }
class Solution {
public:
    
    
    string frequencySort(string s) {
        
        for(auto &it:s)
            mp[it]++;
        sort(s.begin(),s.end(),cmp);
        mp.clear();
        return s;
    }
};