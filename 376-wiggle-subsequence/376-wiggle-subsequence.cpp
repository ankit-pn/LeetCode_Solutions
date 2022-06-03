class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        string s="";
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                continue;
            if(nums[i]-nums[i-1]>=0)
                s+='1';
            else
                s+='0';
        }
        int c=0;
        char req=s[0]=='1'?'0':'1';
        cout<<s<<'\n';
        for(int i=1;i<s.length();i++){
            if(s[i]==req){
                c++;
                req=(s[i]=='1'?'0':'1');
            }
        }
        int x=s.length();
        return c+min(x,1)+1;
    }
};