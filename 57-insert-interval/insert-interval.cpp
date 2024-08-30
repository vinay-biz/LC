class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> ans;
        bool inserted = false;

        for(int i = 0; i < intervals.size(); ++i) {
            if(intervals[i][1] <  newInterval[0]) //Elements before insertion
                ans.push_back(intervals[i]);

            else if(!inserted && intervals[i][0] > newInterval[1]) { //No overlapping case
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                inserted = true;
            }
            else if(inserted) //element already inserted
                ans.push_back(intervals[i]);

            else if(intervals[i][1] >= newInterval[0]) {
                int startTime = min(newInterval[0],intervals[i][0]);
                while(intervals[i][1] < newInterval[1] && i+1 < intervals.size() && intervals[i+1][0] <= newInterval[1]) 
                    ++i;
                
                int endTime = max(intervals[i][1], newInterval[1]);
                ans.push_back({startTime, endTime});
                inserted = true;
            }
        }

        if(!inserted) ans.push_back(newInterval);

        return ans;
    }
};