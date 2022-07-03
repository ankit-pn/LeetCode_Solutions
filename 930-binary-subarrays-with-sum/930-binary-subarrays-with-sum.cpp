class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int k) {
      // what if we need to cacluate atmost k
        if(k-1>=0)
        return atmost(arr,k)-atmost(arr,k-1);
        else
        return atmost(arr,k);
    }
    int atmost(vector<int> &arr,int k){
        int i=0,res=0,n=arr.size();
        // again same length summation approach.
        for(int j=0;j<n;j++){
            if(arr[j])
                k--;
            while(k<0){
                if(arr[i])
                    k++;
                i++;
            }
            res+=(j-i+1);
        }
        return res;
    }
};