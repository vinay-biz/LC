class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int mn1 = INT_MAX, mx1 = INT_MIN, idx = -1;
 
        for(int i=0; i<arr.size(); i++) { //find minimal
            if(arr[i][0] < mn1) {
                mn1 = arr[i][0];
                idx = i;
            }
        }

        for(int i=0; i<arr.size(); i++){ //find maximal
            if(i == idx) continue;
            int n = arr[i].size() - 1;
            mx1 = max(mx1, arr[i][n]);
        }


        int mn2 = INT_MAX, mx2 = INT_MIN; idx = -1;

        for(int i=0; i<arr.size(); i++) { //find maximal
            int n = arr[i].size()-1;
            if(arr[i][n] > mx2){
                mx2 = arr[i][n];
                idx = i;
            }
        }

        for(int i=0; i<arr.size(); i++) {
            if(i == idx) continue;
            mn2 = min(mn2, arr[i][0]);
        }

        int d1 = abs(mn1 - mx1);
        int d2 = abs(mn2 - mx2);
        return max(d1,d2);

    }
};