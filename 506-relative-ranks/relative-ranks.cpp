class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        priority_queue <pair<int,int>> pq; //score,index

        for(int i=0; i<score.size(); i++) pq.push({score[i],i});
        
        int count = 0;
        while(!pq.empty())
        {
            count++;
            pair<int,int> p = pq.top();
            pq.pop();
            if(count > 3) ans[p.second] = to_string(count);
            else if(count == 1) ans[p.second] = "Gold Medal";
            else if(count == 2) ans[p.second] = "Silver Medal";
            else if(count == 3) ans[p.second] = "Bronze Medal";
        }

        return ans;
    }
};