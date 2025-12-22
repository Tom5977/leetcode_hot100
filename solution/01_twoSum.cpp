#include <vector>
#include <map>
#include "../include/list_node.h"
using namespace std;
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, unsigned> hashm;
        vector<int> result(2);
        for(int i = 0; i < nums.size(); i++){
            int another = target - nums[i];
            if(hashm.find(another) != hashm.end()) {
                result[0] = hashm[another];
                result[1] = i;
                break;
            } else {
                hashm[nums[i]] = i;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}


