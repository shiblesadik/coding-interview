class Solution {
public:
  string shiftingLetters(string s, vector<int>& shifts) {
    long long int sum = 0, pre = 0;
    long long int arr[shifts.size() + 1];
    arr[shifts.size()] = 0LL;
    for (int i = shifts.size() - 1; i >= 0; --i) {
      arr[i] = arr[i + 1] + shifts[i];
    }
    for (int i = 0; i < shifts.size(); ++i) {
      sum = ((s[i] - 'a') + arr[i]) % 26;
      s[i] = (sum + 'a');
    }
    return s;
  }
};