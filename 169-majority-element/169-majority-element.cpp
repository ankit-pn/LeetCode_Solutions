class Solution {
public:
    int majorityElement(vector<int>& nums) {
       // initilise majority with begin
        int n=nums.size();
        int majority=nums[0];
        int c=1;
        for(int i=1;i<n;i++){
            // update maojrity element eali
              if(!c)
                majority=nums[i];
            if(nums[i]!=majority)
                c--;
            else
                c++;
          
        }
        return majority;
    }
  
};