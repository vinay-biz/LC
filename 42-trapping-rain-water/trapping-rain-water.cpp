class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 1) return 0;
        int l = 0, r = height.size()-1;
        int leftMax = height[l];
        int rightMax = height[r];
        int res = 0;

        while(l<r)
        {
            if(height[l] < height[r])
            {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            }
            else
            {
                r--;
                rightMax = max(rightMax,height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};