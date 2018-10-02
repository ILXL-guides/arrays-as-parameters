# Arrays as Parameters

You've probably seen how we pass primitive data types as parameters to functions. It is also possible to pass arrays as parameters. However, due to the limitations of the array implementation you need to pass both the array and its size to avoid exceeding its memory bounds.

Below is an example of a function that receives an integer array and it's size. You need to have at least these two parameters to use arrays safely. If you notice, the `size` parameter is used to control the for-loop so that it does not exceed the bounds of the array.

```cpp
void display_values(int values[], int size) {
  for (int i = 0; i < size; i++)
    cout << values[i] << " ";
  cout << "\n";
}
```

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
