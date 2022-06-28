class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        // got falied here , nd doning sorting with the hope that it will get accpeted .
        // final bet will got acceoted
       auto p= dfs(arr,arr.size()-1);
        set<vector<int>> ans;
        for(auto &it:p)
            ans.insert(it);
        vector<vector<int>> fans;
        for(auto &it:ans)
            fans.push_back(it);
        return fans;
        // it should word , expect that we can get tle or mle.
        // my guess , it will be accepted.
        // 
    }
    vector<vector<int>> dfs(vector<int>&arr,int n){
        if(n<0)
            return {{}};
        vector<vector<int>> ans;
        auto p=dfs(arr,n-1);
        ans=p;
        for(auto &it:p){
            it.push_back(arr[n]);
        }
        for(auto &it:p)
            ans.push_back(it);
        return ans;
    }
};