class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;

        for(int i=0; i < n; i++)
        {
            if(ans.empty()) ans.push_back(intervals[i]);
            else
            {
                vector<int>&v = ans.back();
                int y = v[1];

                if(intervals[i][0] <= y) v[1] = max(y, intervals[i][1]);
                else ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};