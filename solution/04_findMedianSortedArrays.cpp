#include <vector>
using namespace std;

class Solution {
public:
    // 在两个数组中找到中间长度下标的值，使用二分法将该长度k走完
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true) {
            //边界条件，思路从下至上
            if (index1 == m) {                  //1数组走至下标为m - 1 + 1即1数组全部小于第k个，则在2数组中找出第k个
                return nums2[index2 + k - 1];   //第k个数，下标则 - 1
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1 + k - 1], nums2[index2 + k - 1]);  //舍弃k - 1个小于中位数的值后，两数组下标所在的第k（1）个即本身中必有中位数，
                                                                            //较小值则为中位数
            }

            int newIndex1 = min(index1 + k / 2 - 1, m - 1);     //使用二分法将k步走完， 并控制下标不超出边界
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;                    //两数组较小值下标前的值必小于中位数，新下标减去旧小标即为走过的k步数，下标相减需+ 1
                index1 = newIndex1 + 1;                         //下标处值较小的数组更新下标，完成二分法往前走的过程，包括下标全部抛弃（+ 1）
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }

        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, totalLength / 2 + 1);
        } 
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }

    }
};