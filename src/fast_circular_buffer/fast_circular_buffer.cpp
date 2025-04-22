#include <iostream>
#include <sched.h>

template <class T> class FastCircBuf {

  struct Node {
    struct Node *nextnode;
    T value;
  };

  FastCircBuf(int size) : m_bufsize(size) {
    m_buf[m_bufsize];

    // instantiate head node
    Node *HeadNode = new Node;
    HeadNode->nextnode = nullptr;

    m_buf[0] = HeadNode;
  };

  ~FastCircBuf() {
    for (int i = 0; i < m_bufsize && i < m_occupation; i++) {
      delete m_buf[i];
    }
  };

  // pushes an element to a new node until the buffer is full
  // returns false once the buffer is full
  // when the buffer is full a call to 'clear' or 'remove' has
  // to be made to free up more space
  bool push_back(T element) {

    bool success = true;

    // handle first element/node
    if (m_occupation == 0) {
      m_buf[0]->value = element;
      m_occupation += 1;

    } else {
      Node *NewNode = new Node;
      NewNode->value = element;
      NewNode->nextnode = nullptr;

      // add to array
      m_buf[m_occupation] = NewNode;

      // previous node points to new node
      m_buf[m_occupation - 1]->nextnode = NewNode;

      m_occupation += 1;

      // max occupation reached
      if (m_occupation == m_bufsize - 1) {
        // point to head node to wrap around
        NewNode->nextnode = m_buf[0];
        success = false;
      }
    }

    return success;
  };

  T at(int index) {
    if (index >= m_bufsize) {
      return -1;
    }
    return m_buf[index];
  };

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
  struct Node *m_buf;
  int m_bufsize;
  int m_occupation = 0;
};

int main(void) {
  std::cout << "Hello World!" << std::endl;
  return 0;
}
