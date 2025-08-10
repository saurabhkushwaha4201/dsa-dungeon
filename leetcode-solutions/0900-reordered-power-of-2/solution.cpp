//S.C : O(1)
class Solution {
public:
    int getVectorCountFormat(int n) {
        int num = 0;

        //256
        //256/10 = 25
        while(n) {
            num += pow(10, n%10);
            n /= 10;
        }

        return num;
    }

    bool reorderedPowerOf2(int n) {
        int input = getVectorCountFormat(n);

        for(int p = 0; p <= 29; p++) {
            if(input == getVectorCountFormat(1 << p)) {
                return true;
            }
        }

        return false;
    }
};

