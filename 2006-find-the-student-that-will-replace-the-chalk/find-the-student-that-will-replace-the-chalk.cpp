class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        sum = accumulate(chalk.begin(), chalk.end(), sum);
        k = k % sum;

        for(int i = 0; i  < chalk.size(); ++i) {
            if(k < chalk[i]) return i;
            k = k - chalk[i];
        }

        return 0;
    }
};