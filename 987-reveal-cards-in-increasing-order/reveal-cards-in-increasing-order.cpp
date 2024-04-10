class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> sortedDeck = deck;
        sort(sortedDeck.begin(), sortedDeck.end());

        vector<int> ans(sortedDeck.size(),-1);
        queue<int> q; for(int i=0; i<deck.size();i++) q.push(i);

        for(int i=0; i<deck.size(); i++)
        {
            ans[q.front()] = sortedDeck[i];
            q.pop();
            int x = q.front();
            q.pop();
            q.push(x);
        }

        return ans;
    }
};