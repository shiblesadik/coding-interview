class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    bool possible = true;
    for (char ch: s) {
      if (ch == '(') st.push(ch);
      else if (ch == ')') {
        if (!st.empty() && st.top() == '(') {
          st.pop();
        } else {
          possible = false;
          break;
        }
      } else if (ch == '{') st.push(ch);
      else if (ch == '}') {
        if (!st.empty() && st.top() == '{') {
          st.pop();
        } else {
          possible = false;
          break;
        }
      } else if (ch == '[') st.push(ch);
      else if (ch == ']') {
        if (!st.empty() && st.top() == '[') {
          st.pop();
        } else {
          possible = false;
          break;
        }
      }
    }
    if (st.size() > 0) possible = false;
    return possible;
  }
};
