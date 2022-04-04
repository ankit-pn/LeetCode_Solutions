class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dfs_max(manager,informTime,i));
        }
        return ans;
    }
    int dfs_max(vector<int> &manager,vector<int> &informTime, int i){
        if(manager[i]!=-1){
            // return informTime[i];
        // else{
            informTime[i]+=dfs_max(manager,informTime,manager[i]);
            manager[i]=-1;
        }
 return informTime[i];
    }
};