class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumber(n);
        uglyNumber[0] = 1;

        int index2 = 0, index3 = 0, index5 = 0;
        int next2 = 2, next3 = 3, next5 = 5;

        for(int i=1; i<n; i++)
        {
            int curr = min(next2, min(next3, next5));
            uglyNumber[i] = curr;

            if(curr == next2)
            {
                index2++;
                next2 = uglyNumber[index2] * 2;
            }

            if(curr == next3)
            {
                index3++;
                next3 = uglyNumber[index3] * 3;
            }

            if(curr == next5)
            {
                index5++;
                next5 = uglyNumber[index5] * 5;
            }
        }

        return uglyNumber[n-1];
    }
};