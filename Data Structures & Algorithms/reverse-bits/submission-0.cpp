class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t count = 0;
        for(int i=0;i<32;i++){
            count = (count << 1);
            int k = n&1;
            n = (n>>1);
            if(k){
                count+=1;
            }
            // count = (count << 1);
        }
        return count;
    }
};
