class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};
        map<int,vector<char>> mp;
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        mp[0]={' '};
        vector<string> ans;
        string temp="";
        dfs(digits,mp,ans,0,temp);
        return ans;
    }
    void dfs(string &s,map<int,vector<char>> &mp,vector<string> &ans,int in,string temp){
            if(in==s.length()){
                // you need to return only when it overflow , not on case of n-1.
                // i hope its 
                
                //periods.
                ans.push_back(temp);
                return ;
            }
            char it=s[in];
            int q=it-'0';
            vector<char> xx=mp[q];
            for(auto &pt:xx){
            temp.push_back(pt);
            dfs(s,mp,ans,in+1,temp);
            temp.pop_back();
                // first mistake, in any case if you including an element , then you need to exclude it also.
            }
    }
};