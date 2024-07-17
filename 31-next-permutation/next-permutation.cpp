class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Find the break even point
        int a=-1,b = 0;
        
        for(int i=nums.size()-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1]) 
            {
                a = i;
                break;
            }
        }

        if(a == -1) return reverse(nums.begin(),nums.end()); //Incase last permutation

        for(int i = nums.size()-1; i > a; i--) //find smallest, but greater then a on right
        {
            if(nums[i] > nums[a]){
            b = i;
            break;
            }
        }

        swap(nums[a],nums[b]); //Swap both

        reverse(nums.begin()+a+1,nums.end());
        
    }
};