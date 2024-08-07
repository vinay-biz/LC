class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int currTime = intervals[0][1];

        for(int i=1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= currTime) //Incase the times are overlapping
            {
                intervals[i-1][1] = max(intervals[i-1][1],intervals[i][1]); //merge or increase end time of perv
                intervals.erase(intervals.begin()+i);
                i--;
                currTime = intervals[i][1];
            }
            else
            {
                currTime = intervals[i][1];            
            }
        }

        return intervals;
    }
};