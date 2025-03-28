#include <iostream>

template <class T> class DynamicArray {
public:
  DynamicArray(int size = 0)
      // allocate a little more than needed to save on heavy reallocation
      // operations
      : m_size(0), m_array(static_cast<T *>(calloc(m_size + 5, sizeof(T)))) {};

  ~DynamicArray() {};

  void push_back(T element) {
    m_occupation++;

    if (m_occupation >= m_size) {
      // allocate a little more than needed again
      m_size += 5;
      m_array = static_cast<T *>(realloc(m_array, m_size * sizeof(T)));
    }
    *(m_array + m_occupation - 1) = element;
  };

  T at(int index) { return *(m_array + index); };

  int size(void) { return m_occupation; };

  int fullsize(void) { return m_size; };

private:
  int m_occupation = 0;
  int m_size;
  T *m_array = nullptr;
};

int main(void) {
  DynamicArray<int> myvec;

  myvec.push_back(3);
  myvec.push_back(2);
  myvec.push_back(10);
  myvec.push_back(13);
  myvec.push_back(15);
  myvec.push_back(16);

  for (int i = 0; i < myvec.size(); i++) {
    std::cout << "vec element " << i << ": " << myvec.at(i) << std::endl;
  }

  return 0;
}
