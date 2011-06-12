double add(double a, double b);

int main()
{
  int i = 0;
  double a = 0;
  while (i < 1000000000) {
    a += 1.0;
    add(a, a);
    i++;
  }
}
