class Solution {
public:
    int balancedString(string s) {
       // not getting approch how to use slding window. 
        // maintaining count.
        unordered_map<char,int> mp;
             int n=s.length();
        for(int i=0;i<n;i++)
            mp[s[i]]++;
   
        int k=n/4;
        int i=0;
        int ans=n+1;
        for(int j=0;j<n;j++){
            mp[s[j]]--;
            while(i<n && mp['Q']<=k && mp['W']<=k && mp['E']<=k && mp['R']<=k){
                mp[s[i]]++;
                ans=min(ans,j-i+1);
                i++;
            }
        }
        return ans;
        
    }
};