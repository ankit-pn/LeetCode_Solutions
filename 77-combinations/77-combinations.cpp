class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k==1){
            vector<vector<int>> ans;
            for(int i=1;i<=n;i++)
                ans.push_back({i});
            return ans;
        }
        if(n==k){
            vector<vector<int>> ans;
            vector<int> temp;
            for(int i=1;i<=n;i++)
                temp.push_back(i);
            ans.push_back(temp);
            return ans;
        }
        // vector<vector<int>> ans;
        auto x=combine(n-1,k-1);
        for(int j=0;j<x.size();j++){
            x[j].push_back(n);
        }
        auto p=combine(n-1,k);
        for(auto &it:p){
            x.push_back(it);
        }
        return x;
        
    }
    // if this got accepted , mf you can do anthing.
    // periods. got accepted.
    
    
    
    
    // vector<int> dfs(){
    //     if(k==1 || n==0 || )
    //     auto temp=dfs(n-1,k-1);
    //     temp.push_back(n);
    //     return temp;
    // }
};