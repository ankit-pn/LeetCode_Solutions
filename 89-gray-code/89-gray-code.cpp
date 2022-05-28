class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> arr;
        for (int i = 0; i < pow(2,n); i++) 
            arr.push_back(i ^ (i/2));
        return arr;
    }
};