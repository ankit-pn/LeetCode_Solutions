class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        // doing it in 0(1) space.
        int n=arr.size();
        int m=arr[0].size();
        int f=0;
        if(arr[0][0]==0)
            f=1;
        int fi=0,fr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    arr[i][0]=0;
                    arr[0][j]=0;
                    if(i==0)
                        fi=1;
                    if(j==0)
                        fr=1;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(arr[i][0]==0){
                for(int j=0;j<m;j++)
                    arr[i][j]=0;
            }
        }
        for(int i=1;i<m;i++){
            if(arr[0][i]==0){
                for(int j=0;j<n;j++)
                    arr[j][i]=0;
            }
        }
        if(arr[0][0]==0){
            if(fr || f)
            for(int i=0;i<n;i++)
                arr[i][0]=0;
            if(fi || f)
            for(int i=0;i<m;i++)
                arr[0][i]=0;
        }
    }
};