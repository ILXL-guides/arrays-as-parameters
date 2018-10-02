#include <iostream>
using namespace std;

void display_values(int values[], int size) {
  for (int i = 0; i < size; i++)
    cout << values[i] << " ";
  cout << "\n";
}

int main() {
  int arr_values[3];
  arr_values[0] = 1;
  arr_values[1] = 5;
  arr_values[2] = 10;

  display_values(arr_values, 3);
  return 0;
}
