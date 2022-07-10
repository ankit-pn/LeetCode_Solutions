class Solution {
public:
    int candy(vector<int> arr) {
        int n=arr.size();
       vector<int> ans(n,1);
        // int i=1,j=n-2;
        // while(i<j){
        //     if(arr[i]>arr[i-1])
        //         ans[i]=ans[i-1]+1;
        //     else if(arr[i]<arr[i-1])
        //         ans[i-1]=ans[i]+1;
        //     if(arr[j]>arr[j+1])
        //         ans[j]=ans[j+1]+1;
        //     else if(arr[j]<arr[j+1])
        //         ans[j+1]=ans[j]+1;
        //     i++;
        //     j--;
        // }
        // int sum=accumulate(ans.begin(),ans.end(),0);
        // return sum;
        
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1])
                ans[i]=ans[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1])
                ans[i]=max(ans[i],ans[i+1]+1);
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};