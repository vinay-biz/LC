class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st; //Height, left extending index
        int maxArea = 0;

        for(int i=0; i<heights.size(); i++)
        {
            int idx = i;
            while(!st.empty() && st.top().first > heights[i])
            {
                pair<int,int> p = st.top();
                st.pop();
                int area = p.first * (i - p.second);
                maxArea = max(area,maxArea);
                idx = p.second;
            }

            st.push({heights[i],idx});
        }

        while(!st.empty())
        {
            pair<int,int> p = st.top();
            st.pop();
            int ans = p.first * (heights.size() - p.second);
            maxArea = max(maxArea, ans);
        }

        return maxArea;
    }
};