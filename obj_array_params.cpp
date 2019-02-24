#include <iostream>

class Point {
private:
  int x_, y_;

public:
  int x() { return x_; }
  void set_x(int x) { x_ = x; }
  int y() { return y_; }
  void set_y(int y) { y_ = y; }
};

void display_points(Point point_arr[], int size) {
  for (int i = 0; i < size; i++)
    std::cout << point_arr[i].x() << ", " << point_arr[i].y() << "\n";
}

int main() {
  Point points[2];
  points[0].set_x(3);
  points[0].set_y(5);

  points[1].set_x(8);
  points[1].set_y(1);

  display_points(points, 2);
  return 0;
}
