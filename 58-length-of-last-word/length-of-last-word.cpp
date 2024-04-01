#include <ranges>
class Solution {
public:
    int lengthOfLastWord(string s) {
        namespace rng = std::ranges;
        static constexpr auto IsAlpha = [](auto c) { return std::isalpha(c); };
        auto reversedWord = rng::reverse_view(s);
        auto lastWordLastLetterIter  = rng::find_if(reversedWord, IsAlpha);
        auto lastWordFirstLetterIter = rng::find_if(rng::next(lastWordLastLetterIter), reversedWord.end(), std::not_fn(IsAlpha));
        return rng::distance(lastWordLastLetterIter, lastWordFirstLetterIter);
    }
};