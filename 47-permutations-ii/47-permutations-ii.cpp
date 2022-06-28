class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      set<vector<int>> ans;
        dfs(nums,ans,0);
    vector<vector<int>> fans;
        for(auto &it:ans)
            fans.push_back(it);
        return fans;
    }
    void dfs(vector<int>&arr,set<vector<int>>&ans,int in){
        if(in>=arr.size())
            ans.insert(arr);
        for(int i=in;i<arr.size();i++){
            swap(arr[in],arr[i]);
            dfs(arr,ans,in+1);
            swap(arr[in],arr[i]);
        }
    }
};