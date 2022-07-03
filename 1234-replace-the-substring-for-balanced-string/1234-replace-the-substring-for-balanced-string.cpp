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
            // well this condn simply implies all of them should have count less than a particular value, if not then we will simple increse right side pointer value to include
            // and when count of all value <=k, like some of them may have count==0 and some of them also have count=k.
            // or atleast one of them will have. well then if we chage all elemnt of that window , then there is grantee that we will get stirng of equal char.
            // becz if we change all the chracter of that string
            // we will put the requid char that we reuired to make string equal to what we want.
            // when all of them are euqla then there will be decrement happed.
            // but then this is gonna be i=j+1.
            // and we will have min ans=0.
            // we start srinking left side of window.
            // incrementing what we have decremented.
            // thanks.
            while(i<n && mp['Q']<=k && mp['W']<=k && mp['E']<=k && mp['R']<=k){
                mp[s[i]]++;
                ans=min(ans,j-i+1);
                i++;
            }
        }
        return ans;
        
    }
};