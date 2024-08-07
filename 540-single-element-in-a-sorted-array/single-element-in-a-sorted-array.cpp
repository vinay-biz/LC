class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int l = 0;
        int r = nums.size()-1;

        while(l < r)
        {
            int mid = (l+r)/2;

            if(mid%2 != 0) mid--;

            if(nums[mid] == nums[mid+1])
            l = mid + 2;

            else r = mid;
        }

        return nums[r];

    }
};