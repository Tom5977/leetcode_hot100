#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>m;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) != m.end()) {
                if (m.size() > ans) ans = m.size();
                i = m[s[i]] + 1;
                m.clear();
            }
            m[s[i]] = i;

        }
        if (m.size() > ans) ans = m.size(); 
        return ans;
    }
};