class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int arr[nums1.size() + nums2.size() + 1];
    int n = nums1.size() + nums2.size();
    int cnt = 0, i = 0, j = 0;
    while (cnt < n) {
      if (i == nums1.size()) {
        if (j == nums2.size()) break;
        else {
          arr[cnt] = nums2[j];
          ++j;
          ++cnt;
        }
      } else if (j == nums2.size()) {
        if (i == nums1.size()) break;
        else {
          arr[cnt] = nums1[i];
          ++i, ++cnt;
        }
      } else if (nums1[i] <= nums2[j]) {
        arr[cnt] = nums1[i];
        ++i, ++cnt;
      } else if (nums1[i] >= nums2[j]) {
        arr[cnt] = nums2[j];
        ++j, ++cnt;
      } else break;
    }
    double d = 0.0;
    if (n % 2) {
      d = arr[n / 2];
    } else {
      d = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    return d;
  }
};
