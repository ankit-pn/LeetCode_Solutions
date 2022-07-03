class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        int c2=0;
        int c1=arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]!=c1){
                c2=arr[i];
                break;
            }
        }
        // cout<<c2<<"\n";
        int ans=0;
        int i=1;
        int curr=0;
        int rq=0;
        while(i<n){
            while(i<n && (arr[i]==c1 || arr[i]==c2)){
                if(arr[i]!=arr[i-1])
                    curr=i;
                    i++;
            }
            // cout<<i<<rq<<"\n";
            ans=max(i-rq,ans);
            rq=curr;
            if(i<n)
            c2=arr[i];
            if(curr<n)
            c1=arr[curr];
        }
        return ans;
    }
};