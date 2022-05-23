class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> ans;
        g(arr,0,ans,0,target);
        return res;
    }
  void g(vector<int>& arr,int c,vector<int> &ans,int index,int target){
      if(c==target){
          res.push_back(ans);
          return ;
      }
      else if(c>target){
          return ;
      }
    for(int i=index;i<arr.size();i++){
        ans.push_back(arr[i]);
        c+=arr[i];
        g(arr,c,ans,i,target);
        ans.pop_back();
        c-=arr[i];
    }
  }
};