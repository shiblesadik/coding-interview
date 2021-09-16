class Solution {
public:
  int maxTurbulenceSize(vector<int>& arr) {
    int maxx = 1, cnt = 0;
    if (arr.size() == 2) {
      if (arr[0] != arr[1]) maxx = 2;
    }
    for (int i = 1; i < arr.size() - 1; ++i) {
      maxx = max(maxx, cnt);
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
        if (cnt == 0 || cnt == 2 || cnt == 1) cnt = 3;
        else ++cnt;
      } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
        if (cnt == 0 || cnt == 2 || cnt == 1) cnt = 3;
        else ++cnt;
      } else {
        maxx = max(maxx, cnt);
        cnt = 0;
        if (arr[i] > arr[i - 1] || arr[i] < arr[i + 1]) {
          cnt = 2;
        } else if (arr[i] < arr[i - 1] || arr[i] > arr[i + 1]) {
          cnt = 2;
        } else {
          cnt = 1;
        }
      }
    }
    maxx = max(maxx, cnt);
    return maxx;
  }
};