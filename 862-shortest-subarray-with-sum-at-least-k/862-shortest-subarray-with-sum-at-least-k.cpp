class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long> arr(n,0);
        arr[0]=nums[0];
            for(int i=1;i<n;i++)
                arr[i]=arr[i-1]+nums[i];
            deque<long> d;
            long res=n+1;
            for(long i=0;i<n;i++){
                if(arr[i]>=k)
                    res=min(res,i+1);
                while(d.size() && arr[i]-arr[d.front()]>=k)
                    res=min(res,i-d.front()),d.pop_front();
                while(d.size() && arr[i]<=arr[d.back()])
                    d.pop_back();
                d.push_back(i);
            }
            return res>n?-1:res;
    }
};