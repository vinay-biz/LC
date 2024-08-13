class Solution {
public:
    void solve(vector<int>&cand, int n, int i, int tar, vector<vector<int>>&ans, vector<int>&res){
        if(tar == 0){
            ans.push_back(res) ;
            return ;
        }

        if(i == n) return ;

        for(int idx = i; idx<n; idx++){
            if(tar >= cand[idx]){
                res.push_back(cand[idx]) ;
                solve(cand, n, idx, tar-cand[idx], ans, res) ;
                res.pop_back() ;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        int n = cand.size() ;
        vector<vector<int>>ans ;
        vector<int>res ;
        solve(cand, n, 0, tar, ans, res) ;

        return ans ;
    }
};