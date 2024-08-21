class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        num = num + (t << 1);
        return num;
    }
};