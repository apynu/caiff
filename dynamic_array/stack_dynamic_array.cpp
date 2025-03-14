#include <cstring>
#include <iostream>

template <class T> class DynamicArray {
public:
  DynamicArray(void) : internalarraysize(0) {};
  DynamicArray(int size) : internalarraysize(size) { internalarray[size]; };

  ~DynamicArray() {};

  void push_back(T element) {

    if (internalarraysize != 0) {
      currarrayoccupation += 1;
    }

    if (currarrayoccupation >= internalarraysize) {

      if (currarrayoccupation > internalarraysize) {
        internalarraysize = currarrayoccupation;
      }

      T tmparray[internalarraysize + 1];

      for (int i = 0; i < internalarraysize; i++) {
        tmparray[i] = internalarray[i];
        // std::cout << tmparray[i] << std::endl;
      }

      tmparray[internalarraysize] = element;

      memset(internalarray, internalarraysize,
             sizeof(internalarray[internalarraysize]));

      // internalarray[internalarraysize];

      for (int i = 0; i < internalarraysize; i++) {
        std::cout << tmparray[i] << std::endl;
        internalarray[i] = tmparray[i];
      }

      internalarraysize += 1;
    }
  };

  T at(int index) { return internalarray[index]; };

private:
  int currarrayoccupation = 0;
  int internalarraysize;
  T internalarray[];
};

int main(void) {
  DynamicArray<int> myvec;
  myvec.push_back(int(3));
  myvec.push_back(int(2));
  myvec.push_back(int(10));
  std::cout << "first vec element: " << myvec.at(0) << std::endl;
  std::cout << "second vec element: " << myvec.at(1) << std::endl;
  std::cout << "third vec element: " << myvec.at(2) << std::endl;
  return 0;
}
