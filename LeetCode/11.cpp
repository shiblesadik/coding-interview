class Solution {
public:
  vector<int> arr;
  int value;
  int l_maxx, r_maxx, a, b;
  pair<int, int> tree[410005], q_l, q_r;

  void build(int indx, int l, int r) {
    if (l == r) {
      tree[indx].first = arr[l];
      tree[indx].second = l;
      return;
    }
    build(indx << 1, l, (l + r) >> 1);
    build((indx << 1) + 1, ((l + r) >> 1) + 1, r);
    if (tree[indx << 1].first > tree[(indx << 1) + 1].first) {
      tree[indx] = tree[indx << 1];
    } else {
      tree[indx] = tree[(indx << 1) + 1];
    }
  }

  pair<int, int> query_left(int indx, int l, int r) {
    if (r_maxx < l || r < l_maxx) return {199999999, 199999999};
    if (l_maxx <= l && r <= r_maxx) {
      if (l == r) return tree[indx];
      else if (tree[indx].first < value) return {199999999, 199999999};
      else if (tree[indx << 1].first >= value) {
        return query_left(indx << 1, l, (l + r) >> 1);
      } else return query_left((indx << 1) + 1, ((l + r) >> 1) + 1, r);
    }
    pair<int, int> ff = query_left(indx << 1, l, (l + r) >> 1);
    pair<int, int> ss = query_left((indx << 1) + 1, ((l + r) >> 1) + 1, r);
    if (ff.first == 199999999) return ss;
    else if (ss.first == 199999999) return ff;
    else if (ff.first >= value) return ff;
    else return ss;
  }

  pair<int, int> query_right(int indx, int l, int r) {
    if (r_maxx < l || r < l_maxx) return {199999999, 199999999};
    if (l_maxx <= l && r <= r_maxx) {
      if (l == r) return tree[indx];
      else if (tree[indx].first < value) return {199999999, 199999999};
      else if (tree[(indx << 1) + 1].first >= value) {
        return query_right((indx << 1) + 1, ((l + r) >> 1) + 1, r);
      } else return query_right(indx << 1, l, (l + r) >> 1);
    }
    pair<int, int> ff = query_right(indx << 1, l, (l + r) >> 1);
    pair<int, int> ss = query_right((indx << 1) + 1, ((l + r) >> 1) + 1, r);
    if (ss.first == 199999999) return ff;
    else if (ff.first == 199999999) return ss;
    else if (ss.first >= value) return ss;
    else return ff;
  }


  int maxArea(vector<int>& height) {
    if (height.size() == 1) {
      return 0;
    } else if (height.size() == 2) {
      return min(height[0], height[1]);
    }
    arr = height;
    arr.insert(arr.begin(), 0);
    build(1, 1, arr.size() - 1);
    int maxx_area = 0;
    int c;
    for (int i = 1; i < arr.size(); ++i) {
      value = arr[i];
      l_maxx = 1,
      r_maxx = i - 1;
      q_l = query_left(1, 1, arr.size() - 1);
      l_maxx = i + 1;
      r_maxx = arr.size() - 1;
      q_r = query_right(1, 1, arr.size() - 1);
      c = 0;
      a = q_l.second, b = q_r.second;
      if (a == 199999999) a = i;
      if (b == 199999999) b = i;
      if(i == 1){
        if (arr[b] < value) b--;
        c = (b - i);
        maxx_area = max(maxx_area, c * value);
      }else if(i == arr.size() - 1){
        if (arr[a] < value) a++;
        c = (i - a);
        maxx_area = max(maxx_area, c * value);
      }else{
        if (arr[a] < value) a++;
        if (arr[b] < value) b--;
        c = b - a;
        maxx_area = max(maxx_area, c * value);
      }
    }
    return maxx_area;
  }
};
