class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int count = 0;

        while( temp )
        {
            int rem = temp%10;
            if(num%rem == 0) count++;
            temp = temp/10;
        }

        return count;
    }
};