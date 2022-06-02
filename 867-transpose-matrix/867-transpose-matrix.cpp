class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
               temp.push_back(arr[j][i]); 
            }
            ans.push_back(temp);
            
        }return ans;
    }
        
    
};