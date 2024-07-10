class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;

        for(int index = 0; index < logs.size(); index++)
        {
            if(logs[index] == "../")
            { 
                if(ans > 0) ans--;
            }
            else if(logs[index] == "./") continue;

            else ans++;
        }

        return ans;
    }
};