class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int i=0,res=0,n=arr.size();
        for(int j=0;j<n;j++){
            if(arr[j]==0)
                k--;
            while(k<0){
                if(arr[i]==0)
                    k++;
                i++;
            }
            res=max(j-i+1,res);
        }
        return res;
    }
};