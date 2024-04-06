class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft;
        vector<int> maxRight(height.size());

        int mx = 0;
        for(int i=0; i<height.size(); i++)
        {
            maxLeft.push_back(mx);
            mx = max(mx,height[i]);
        }

        mx = 0;
        for(int i=height.size()-1; i>=0; i--)
        {
            maxRight[i]=mx;
            mx = max(mx,height[i]);
        }

        vector<int> diff;
        
        int ans = 0;
        for(int i=0; i<height.size(); i++)
        {
            int x = min(maxLeft[i],maxRight[i]) - height[i];
            (x>0) ? ans += x : ans = ans;
        }

        return ans;
    }
};