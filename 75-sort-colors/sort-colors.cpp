class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0) zero++;
            if(nums[i] == 1) one++;
        }

        int index = 0;
        while(zero)
        {
            nums[index++] = 0;
            zero--;
        }

        while(one)
        {
            nums[index++] = 1;
            one--;
        }

        while(index < nums.size())
        {
            nums[index++] = 2;
        }
    }
};