class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxL;
        vector<int> maxR(height.size());

        int mx = 0;
        for(int i=0; i<height.size(); i++)
        {
            maxL.push_back(mx);
            mx = max(mx, height[i]);
        }

        mx = 0;
        for(int i=height.size()-1; i>=0; i--)
        {
            maxR[i] = mx;
            mx = max(mx,height[i]);
        }

        int ans = 0;
        
        for(int i=0; i<height.size(); i++)
        {
            int temp = min(maxL[i],maxR[i]) - height[i];
            if(temp>0) ans += temp;
        }

        return ans;
    }
};