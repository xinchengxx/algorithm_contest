class Solution {
   public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        long long re = x;
        while(re * re > x){
            re = (x / re + re) >> 1;
        }
        return re;
    }
};