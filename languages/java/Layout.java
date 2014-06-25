public class Layout { // Class Declaration
  int x;

  Layout(int x) {
    this.x = x;
  }

  int sum(int y) {
    if ( x > 0) {
      return x + y;
    } else if ( x < 0) {
      int res = -x + y;
      return res * 117;
    } else {
      int sum = 0;
      for (int i = 0; i < 10; i++) {
        sum += (y -i) * (y - i);
      }
      return sum;
    }
  }

  static boolean checkdate(int mth, int day) {
    int length;

    switch (mth) {
      case 2:
        length = 28;
        break;
      case 4:case 6:case 9:case 11:
        length = 30;
        break;
      case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        length = 31;
        break;
      default:
        return false;
    }
    return (day >= 1) && (day <= length);
  }

  public static void main(String[] arg) {
    Layout layout = new Layout(10);
    System.out.println(layout.sum(10));
    System.out.println(Layout.checkdate(2, 28)); // Accessed as a static variable
  }
}
