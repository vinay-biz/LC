class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;

        for(int index = 0; index < logs.size(); index++)
        {
            if(logs[index] == "../")
            { 
                ans = (ans == 0) ? 0 : ans-1;
            }
            else if(logs[index] == "./") continue;

            else ans++;
        }

        return ans;
    }
};