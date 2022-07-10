class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    vector<int> partitionLabels(string s) {
        // well the prolbem is same as stating and merging interval.
        // best way ot write it in ocpy for further disscrption.
        
        map<char,vector<int>> mp;
        int n=s.length();
        vector<bool> check(26,0);
        vector<bool> check1(26,0);
        for(int i=0;i<n;i++){
            if(check[s[i]-'a']==0){
                mp[s[i]]={i,-1};
                check[s[i]-'a']=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(check1[s[i]-'a']==0){
                vector<int> temp = mp[s[i]];
                temp[1]=i;
                mp[s[i]]=temp;
                check1[s[i]-'a']=1;
            }
        }
        vector<vector<int>> ivn;
        for(auto &it:mp){
            ivn.push_back(it.second);
        }
        for(auto it:ivn){
            cout<<it[0]<<" "<<it[1]<<"\n";
        }
        sort(ivn.begin(),ivn.end());
        
        int i=1,end=ivn[0][1];
        vector<int> ans;
        int n1=ivn.size();
        while(i<n1){
            if(ivn[i][0]>end){
                ans.push_back(end);
            }
            end= max(end,ivn[i][1]);
            i++;
        }
        ans.push_back(end);
        for(auto it:ans)
            cout<<it<<" ";
        vector<int> res;
        res.push_back(ans[0]+1);
        for(int i=1;i<ans.size();i++){
            res.push_back(ans[i]-ans[i-1]);
        }
        
        return res;
    }
};