class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1=nums[0],m2=nums[0],c1=0,c2=0;
        int n=nums.size();
        for(auto it:nums){
            if(it==m1)
                c1++;
            else if(it==m2)
                c2++;
            else if(c1==0){
                m1=it;
                c1++;
            }
            else if(c2==0){
                m2=it;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        vector<int> ans;
        cout<<m1<<" "<<m2<<"\n";
        for(auto it:nums){
            if(it==m1)
                c1++;
            if(it==m2)
                c2++;
        }
        if(c1>n/3)
            ans.push_back(m1);
         if(c2>n/3 && m1!=m2)
            ans.push_back(m2);
        return ans;
    }
};