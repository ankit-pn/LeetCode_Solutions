class Solution {
public:
    int numberOfSubstrings(string s) {
        // classic sliding window problem.
        unordered_map<char,int> mp;
        int i=0,res=0,n=s.length();
        for(int j=0;j<n;j++){
            mp[s[j]]++;
            // if all of them are positive , we need to shift left value, becz we encounterd a array and all we need is to look after that.
            while(mp['a'] && mp['b'] && mp['c']){
                mp[s[i]]--;
                i++;
            }
            // we still have no fucking idea what will be number, let us spoose we 
            // get out first subarray then all we need to add i.
            // then gain j changes and we get all == 1 , we are taking about abcabc wala example, then what we need is to figure out 
            // we have to add 2 , and why? becz i incremented and bca,abca
            // well it is working.
            res+=i;
        }
        return res;
    }
};