#include <iostream>

void increment(int *value) {
  // dereference to manipulate data before increment
  // in C++, we can automatically not make the arguments pointers
  // but instead, normal functions and reference the data
  // this make it possible to do things like ++value without with deference operator *
  ++*value;
}

void increment_ref(int &item) {
    ++item;
}

int main() {
  int var = 8;
  int a = 12;
  int b = 12;

  std::cout << "var: " << var << "\n";
  std::cout << "a: " << a << "\n";
  std::cout << "b: " << b << "\n";

  // void pointers
  // void pointers can be NULL like all other pointers
  // before you can deference a void pointer, you have to type cast to the 
  // object type it is pointing to first.
  void *var_ptr = nullptr;
  var_ptr = &var;

  // we can assign types to the pointers
  // and deference them if the type of the pointer is the same to the data of the address
  // that is the address of the pointee.
  int *ptr = &a;
  *ptr = 20; 

  // referencing the var b to the function increment
  increment(&b);

  // c++ referencing with increment_ref function
  int x = 14;
  increment_ref(x);
  std::cout << "x: " << x << "\n";

  // print the value of b after using the increment function on it
  std::cout << "b after: " << b << "\n"; 
  
  // print the value of a after deferencing it with the it's pointer ptr
  std::cout << "a after: " << a << "\n"; 

  // printing the address of the value the pointer is pointing to
  std::cout << "Pointee address for var: " << var_ptr << "\n";

  // This instead will print the address of the pointer.
  std::cout << "Address of the Pointer itself: " << &var_ptr << "\n";

  // As said early, we have to type cast void pointers before we can deference them
  // to this part, we access the value of the pointee using the type casting.
  std::cout << *(static_cast<int *>(var_ptr)) << "\n";

  std::cin.get();
}