class Solution {
public:
    int characterReplacement(string s, int k) {
        // map for charcter ...
        vector<int> arr(26,0);
        // applying slding windows;
        int i=0,j=0,ans=0;
        while(j<s.length()){
            arr[s[j]-'A']++;
            int x=*max_element(arr.begin(),arr.end());
            int rk=j-i+1-x;
            if(rk>k){
                arr[s[i]-'A']--;
                int y=*max_element(arr.begin(),arr.end());
                rk=j-i+1-y;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};