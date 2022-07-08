class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        // it is __buildin_popcount not __build_in_pop_count. period.
        return __builtin_popcount(n);
    }
};