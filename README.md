# Arrays as Parameters

You've probably seen how we pass primitive data types as parameters to functions. It is also possible to pass arrays as parameters. However, due to the limitations of the array implementation you need to pass both the array and its size to avoid exceeding its memory bounds.

Below is an example of a function that receives an integer array and it's size. You need to have at least these two parameters to use arrays safely.

```cpp
void display_values(int values[], int size) {
  for (int i = 0; i < size; i++)
    cout << values[i] << " ";
  cout << "\n";
}
```

If you notice, the array parameter called `values` does not provide the size of the array. For a 1-dimensional array, the compiler is able to use the array even without its maximum size which makes functions more flexible. However, we still need the `size` parameter because it is the only way to know which indices of the array are safe to access. 

If you look at the example, `size` is used to control the for-loop that accesses the array's elements. Take note that the `size` parameter may not necessarily be the maximum size of the array. Imagine an array with 100 elements, but currently there are only 8 elements in the array whose values were assigned. When we pass 8 as the array's size, then the function would only work with the first 8 elements instead of the entire 100.

Below is an example of how `display_values` can be called. Take note that we use the name of the array as the argument to the function call. Using the name as an argument passes the address of the array to the function and allows it to access all the array's elements. We also pass the size of the array to ensure that the function does not exceed the array's bounds.

```cpp
int main() {
  int arr_values[3];
  arr_values[0] = 1;
  arr_values[0] = 5;
  arr_values[0] = 10;
  
  display_values(arr_values, 3);
  return 0;
}
```
# Object Arrays as Parameters

Arrays containing abstract data types can also be passed as parameters and work the same way. The only difference is that instead of storing a primitive data type (e.g., `int`, `float`, `char`), we deal with objects. This means that we have access to each object's data members and methods that are declared public.

```cpp
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
  points[2].set_y(1);
  
  display_points(points, 2);
  return 0;
}
```

In the example above, the `display_points` function has access to `point_arr` that is an array of `point` objects. Each element of the array is still accessible using the bracket notation, but take note this gives access to a `point` object. Therefore, we are able to access the data members and methods of the array element by combining the bracket notation with the dot notation. Specifically, the example shows how we access the ith element of `point_arr`, which is a `point` object, and call its `x()` method. This is possible because `x()` is a public method defined in the `point` class.

# Common errors 
## Passing an array and an array element are two different things
This function call passes the entire array

```cpp
display_values(arr_values, 3);
```

While this function passes an element of an array. Take note of `square`'s parameter which is an `int` and not an array.

```cpp
int square(int val) { 
  return val * val; 
}

int main() {
  int arr_values[3];
  arr_values[0] = 1;
  arr_values[0] = 5;
  arr_values[0] = 10;
  
  int squared_value = square(arr_values[0]);
}
```
