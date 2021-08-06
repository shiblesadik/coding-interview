class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    int value = 0;
    for (int i: piles) {
      value ^= i;
    }
    if (value & 1) return true;
    else return false;
  }
};
