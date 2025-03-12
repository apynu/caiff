#include <filesystem>
#include <iostream>

template <class T> class DynamicArray {
public:
  DynamicArray(void) : internalarraysize(0) { internalarray[0]; };
  DynamicArray(int size) : internalarraysize(size) { internalarray[size]; };

  ~DynamicArray() {};

  void push_back(T element) {
    currarrayoccupation += 1;
    if (currarrayoccupation == internalarraysize) {
      int *tmparray[internalarraysize + 1];
      for (int i = 0; i < internalarraysize; i++) {
        tmparray[i] = internalarray[i];
      }
      tmparray[internalarraysize] = &element;

      internalarray = tmparray;
    }
  };

private:
  int currarrayoccupation;
  int internalarraysize;
  int *internalarray[];
};

int main(void) {
  DynamicArray<int> myvec;
  myvec.push_back(10);
  std::cout << "Hello World" << std::endl;
  return 0;
}
