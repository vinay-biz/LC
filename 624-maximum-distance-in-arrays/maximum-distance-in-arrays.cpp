class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int sz = arr.size();
        int mn1 = INT_MAX, mx1 = INT_MIN, idx1 = -1;
        int mn2 = INT_MAX, mx2 = INT_MIN, idx2 = -1;
 
        for(int i = 0; i < sz; i++) { //find minimal and maximal
            if(arr[i][0] < mn1) {
                mn1 = arr[i][0];
                idx1 = i;
            }
            int n = arr[i].size() - 1;
            if(arr[i][n] > mx2){
                mx2 = arr[i][n];
                idx2 = i;
            }
        }

        for(int i = 0 ; i < sz ; i++){ //find maximal adn minimal
            if(i != idx1) {
                int n = arr[i].size() - 1;
                mx1 = max(mx1, arr[i][n]);
            }
            if(i != idx2) {
                mn2 = min(mn2, arr[i][0]);
            }
        }

        return max(abs(mn1 - mx1),abs(mn2 - mx2));

    }
};