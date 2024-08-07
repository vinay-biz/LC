class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //first one should be even indexed
        //second one should be odd indexed

        int l = 0;
        int r = nums.size()-1;

        while(l <= r)
        {
            int mid = (l+r)/2;

            if( ((mid == 0) || nums[mid-1] != nums[mid]) && (mid == nums.size()-1 || nums[mid+1] != nums[mid]))
            {
                return nums[mid];
            }

            if((mid%2 == 0 && (mid == 0 || nums[mid-1] != nums[mid])) || (mid%2 != 0 && nums[mid-1] == nums[mid]))
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }

        return -1;

    }
};