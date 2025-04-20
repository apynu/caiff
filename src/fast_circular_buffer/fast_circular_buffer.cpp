#include <iostream>
#include <sched.h>

template <class T> class FastCircBuf {
  struct Node {
    struct Node *nextnode;
    T value;
  };

  FastCircBuf(const int size) : m_bufsize(size) { m_buf[m_bufsize]; };

  ~FastCircBuf();

  // pushes an element to a new node until the buffer is full
  // returns false once the buffer is full
  // when the buffer is full a call to 'clear' or 'remove' has
  // to be made to free up more space
  bool push_back(T) { return false; };

  void at(int index) {};

  // free whole buffer
  void clear() {
    for (int i = 0; i < m_bufsize; i++) {
      m_buf[i] = 0x0; // set all elements of the buffer to nullbytes
    }
    m_occupation = 0; // reset occupation
  };

  void remove(int index) {};

  int size() const { return m_bufsize; };

private:
  int *m_buf;
  const int m_bufsize;
  int m_occupation = 0;
};

int main(void) {
  std::cout << "Hello World!" << std::endl;
  return 0;
}
