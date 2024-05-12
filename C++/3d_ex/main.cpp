#include <iostream>
#include <vector>

using namespace std;

struct Step {
  int r;
  int x;
  int y;
  int q;
};

void extendedEuclid(int, int, vector<Step> &, int &, int &);
void printTable(vector<Step> &);

int main() {
  int c, m;
  cin >> c >> m;

  vector<Step> steps;
  int d, gcd;
  extendedEuclid(c, m, steps, d, gcd);
  printTable(steps);

  if (gcd == 1)
    cout << (d % m + m) % m << endl;
  else
    cout << "the numbers must be mutually inverse" << endl;

  return 0;
}

void extendedEuclid(int c, int m, vector<Step> &steps, int &d, int &gcd) {
  int x = 0, y = 1, lastx = 1, lasty = 0, temp;
  while (m != 0) {
    int q = c / m;
    int r = c % m;

    c = m;
    m = r;

    temp = x;
    x = lastx - q * x;
    lastx = temp;

    temp = y;
    y = lasty - q * y;
    lasty = temp;

    steps.push_back({c, lastx, lasty, q});
  }
  steps.push_back({m, x, y, 0});
  gcd = c;
  d = lastx;
}

void printTable(vector<Step> &steps) {
  cout << "r\t\tx\t\ty\t\tq\n";
  for (const Step &step : steps) {
    cout << step.r << "\t\t" << step.x << "\t\t" << step.y << "\t\t" << step.q
         << "\n";
  }
}