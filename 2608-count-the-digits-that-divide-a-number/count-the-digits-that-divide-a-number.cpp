class Solution {
public:
    int countDigits(int num)
    { 
        int cnt=0;
        int oldn=num;
        while(num!=0)
        {
            int val = num % 10;
            if(oldn % val == 0)
            {
                cnt++;
            }
        num=num/10;    
        }  
    return cnt;    
    }
};