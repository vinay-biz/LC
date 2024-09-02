class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i = 0; i < chalk.size(); ++i)
            sum += (long long)chalk[i];
    
        sum = k%sum;
        if(sum == 0) return 0;

        for(int i = 0; i < chalk.size(); i++) {
            if(sum - chalk[i] < 0) return i;
            sum = sum - chalk[i]; 
        }

        return 0;
    }
};