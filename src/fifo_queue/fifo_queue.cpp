#include <algorithm>
#include <iostream>
#include <vector>

// TODO: some constraints so that T can't be too big
//       as performance will suffer if it is
template <class T> class Fifo {
public:
  Fifo(int size = 0) {
    m_InternalQ.reserve(size); // pre allocate for better performance
  }

  void addToFifo(T element) {
    // this is where performance lacks
    // each item always needs to be moved one to the right
    // when adding a new one
    m_InternalQ.insert(m_InternalQ.begin(), element);
  }

  // TODO: implement
  T removeFromFifo(void) { return m_InternalQ[0]; }

private:
  std::vector<T> m_InternalQ;
};

int main(void) {
  std::cout << "Hello World" << std::endl;
  return 0;
}
