#include <iostream>
using namespace std;

main() {
  int N, prob = 1;
  for (cin >> N; N--;) {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Case #" << prob++ << ": ";
    if ((x2-x1)*(y3-y1) == (x3-x1)*(y2-y1)) {
      cout << "not a triangle" << endl;
      continue;
    }
    bool obtuse = false, right = false, iso = false;
    for (int swp = 0; swp < 3; swp++) {
      int ln1 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
      int ln2 = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
      int ln3 = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
      if (ln3 > ln1 + ln2) obtuse = true;
      if (ln3 == ln1 + ln2) right = true;
      if (ln1 == ln2) iso = true;
      {int x = x1, y = y1; x1 = x2; y1 = y2; x2 = x3; y2 = y3; x3 = x; y3 = y;}
    }
    if (iso) cout << "isosceles "; else cout << "scalene ";
    if (right) cout << "right triangle" << endl;
    else if (obtuse) cout << "obtuse triangle" << endl;
    else cout << "acute triangle" << endl;
  }
}
