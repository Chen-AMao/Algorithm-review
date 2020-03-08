class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int low = 1;
        int high = x/2+1; // to minimize the searching range
        int mid;
        while (low+1 < high) {
            mid = (low + high) / 2;
            if (x / mid < mid) { // mid*mid may overflow 
                high = mid;
            } else {
                low = mid;
            }
        }
        return low;
    }
};
