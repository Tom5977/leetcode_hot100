#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, bool>m;
        int ans = 0;
        for (auto c : s) {
            if (m[c]) {
                if (m.size() > ans) ans = m.size();
                m.clear();
            }
                m[c] = true;

        }
        return ans;
    }
};