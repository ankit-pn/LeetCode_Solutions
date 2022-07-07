class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.length();
       return backtrack(s,0,n-1);
    }
    bool is_palindrome(string s){
        string t=s;
        reverse(t.begin(),t.end());
        return t==s;
    }
    vector<vector<string>> backtrack(string &s,int start,int end){
        vector<vector<string>> ans;
        if(end==start){
            ans.push_back({s.substr(0,1)});
        return ans;
        }
        int j=0;
        while(j<end){
        string ans1 = s.substr(end-j,j+1);
        string ans2 = s.substr(start,end-j);
            if(!is_palindrome(ans1)){
                j++;
                continue;
            }
        vector<vector<string>> temp1=backtrack(s,start,end-j-1);
        for(auto &it:temp1){
            it.push_back(ans1);
        }
            for(auto &it:temp1)
                ans.push_back(it);
            j++;
        }
        if(is_palindrome(s.substr(start,end+1)))
            ans.push_back({s.substr(start,end+1)});
        return ans;
    }
};