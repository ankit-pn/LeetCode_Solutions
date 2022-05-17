class Solution {
public:
    bool exist(vector<vector<char>>& arr, string word) {
         int n=arr.size(),m=arr[0].size();
        int curr=0,i=0,j=0;
        vector<vector<bool>> v(n,vector<bool>(m,0));
        bool res=false;
        // return helper(arr,word,0,0,0,v);
        // for(auto it:v)
        //     for(auto it1:it)
        //         cout<<it1<<" ";
        for(int i=0;i<n;i++){
            // cout<<"hrgr";
            for(int j=0;j<m;j++){
                if(helper(arr,word,i,j,0,v)){
                    cout<<i<<" "<<j;
                    return 1;
                }
            }
        }
        return res;
       
    }
    bool helper(vector<vector<char>>& arr, string s,int i,int j,int curr,vector<vector<bool>> &v){
        int n=arr.size(),m=arr[0].size();
        if(curr==(s.length()))
            return 1;
        else if(curr>=s.length())
            return 0;
        if(i>=n || j>=m || i<0 || j<0)
            return 0;
          if(v[i][j]==1)
            return 0;
        v[i][j]=1;
        if(s[curr]==arr[i][j]){
            curr++;  
            bool t = helper(arr,s,i+1,j,curr,v) || helper(arr,s,i,j+1,curr,v) || helper(arr,s,i-1,j,curr,v) || helper(arr,s,i,j-1,curr,v);
            v[i][j]=0;
            return t;
        }
        else
        { v[i][j]=0;
            return 0;
        }
    }
};