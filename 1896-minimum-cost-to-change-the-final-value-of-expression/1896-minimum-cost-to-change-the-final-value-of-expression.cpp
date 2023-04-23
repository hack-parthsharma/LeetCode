class Solution {
public:
  int minOperationsToFlip(string expression) {
    stack<array<int, 3>> s;
    s.push({0, 0, 0});
    for (char e : expression) {
      if (e == '(')
        s.push({0, 0, 0});
      else if (e == '&' || e == '|')
        s.top()[2] = e;
      else {        
        if (isdigit(e)) s.push({e != '0', e != '1', 0});
        auto [r0, r1, _] = s.top(); s.pop();
        auto [l0, l1, op] = s.top(); s.pop();
        if (op == '&') {
          s.push({min(l0, r0),
                  min(l1 + r1, min(l1, r1) + 1),
                  0});
        } else if (op == '|') {
          s.push({min(l0 + r0, min(l0, r0) + 1),
                  min(l1, r1),
                  0});
        } else {
          s.push({r0, r1, 0});
        }
      }
    }
    return max(s.top()[0], s.top()[1]);
  }
};