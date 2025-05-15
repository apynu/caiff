#include <iostream>
#include <vector>

/// faster circular buffer implementation using an array
template <class T> class fast_circ_buf {
public:
  fast_circ_buf(int Size) : m_BufSize(Size) { m_Buf.resize(m_BufSize); };

  // adds one element to the circular buffer
  // returns false once the buffer is full, otherwise returns true
  // except if the override is set, then it'll always return true and override
  // elements
  bool push_back(T Element) {
    bool Success = true;

    // there is still space for a new element
    if (m_Occupation <= m_BufSize)
      m_Buf.push_back(Element);

    // there is no space but the override flag is set
    else if (m_override)
      // NOTE: this is kinda shit tbh
      m_Buf.push_back(Element);
    else
      Success = false;

    m_Buf.push_back(Element);

    for (int i = 0; i < m_BufSize; i++) {
      std::cout << m_Buf[i] << std::endl;
    }

    return Success;
  };

  // returns the element at the current index
  // index wraps around
  T at(int Index) {

    /*
    for (int i = 0; i < m_BufSize; i++) {
      std::cout << m_Buf.at(i) << std::endl;
    }
    */

    while (Index > m_BufSize) {
      Index = m_BufSize % Index;
      // printf("Index: %d\nBufSize: %d\n", Index, m_BufSize);
    }
    // printf("Index: %d\nBufSize: %d\n", Index, m_BufSize);
    return m_Buf.at(Index - 1);
  }

  // sets whether push_back should simply override the elements
  // when the buffer is full
  void set_override(bool override) { m_override = override; };

  // clears internal data array
  /// sort of a pseudo clear, simply releases all objects to be overwritten
  void clear() { m_Occupation = 0; };

  // allocate memory based on new size
  void realloc(int size) {
    // set new buffer size
    m_BufSize = size;

    // resize internal storage, which will only resize if m_BufSize is
    // bigger than the current capacity
    m_Buf.resize(m_BufSize);
  };

private:
  std::vector<T> m_Buf;
  int m_BufSize;
  int m_Occupation = 0;
  bool m_override = false;
};

int main(void) {
  fast_circ_buf<int> CircBuf(5);
  int testval = 100;

  CircBuf.set_override(true);
  CircBuf.push_back(testval);
  CircBuf.push_back(2);
  CircBuf.push_back(3);
  CircBuf.push_back(4);
  CircBuf.push_back(5);

  std::cout << CircBuf.at(0) << std::endl;

  CircBuf.at(8);
  // std::cout << "Index 7: " << CircBuf.at(8) << std::endl;

  return 0;
}
