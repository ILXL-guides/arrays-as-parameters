#include <iostream>
using namespace std;

class point {
private:
  int _x, _y;
public:
  int x() { return _x; }
  void set_x(int x) { _x = x; }
  int y() { return _y; }
  void set_y(int y) { _y = y; }
};

void display_points(point point_arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << point_arr[i].x() << ", " << point_arr[i].y() << "\n";
}

int main() {
  point points[2];
  points[0].set_x(3);
  points[0].set_y(5);

  points[1].set_x(8);
  points[1].set_y(1);

  display_points(points, 2);
  return 0;
}
