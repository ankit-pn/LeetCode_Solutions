class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& supplies) {
        set<string> supp;
        int n=rec.size();
        for(int i=0;i<supplies.size();i++)
            supp.insert(supplies[i]);
        vector<bool> re(n,0);
        vector<bool> pr(n,0);
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(dfs(rec,ing,supp,re,pr,i))
                ans.push_back(rec[i]);
        }
        return ans;
    }
    bool dfs(vector<string> &rec,vector<vector<string>>& ing,set<string>& supp,vector<bool> &re,vector<bool> &pr,int in){
        if(re[in])
            return re[in];
        bool xx=1;
        if(pr[in]==1)
            return false;
        pr[in]=1;
        for(auto it:ing[in]){
            if(supp.find(it)==supp.end()){
                bool f=0;
                bool pp=0;
                for(int i=0;i<rec.size();i++){
                    if(it==rec[i]){
                        f=1;
                     pp=dfs(rec,ing,supp,re,pr,i);
                    }
                }
                if(f){
                    if(!pp){
                        xx=0;
                        break;
                    }   
                }
                else{
                    xx=0;
                    break;
                }
            }
        }
        pr[in]=2;
        re[in]=xx;
        return xx;
    }
};