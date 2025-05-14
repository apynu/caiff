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
    if (m_Occupation <= m_BufSize) {
      if (m_override)
        m_Buf.push_back(Element);
      else
        Success = false;
    }

    return Success;
  };

  // returns the element at the current index
  // index wraps around
  T at(int Index) {
    Index = Index % m_BufSize;
    return m_Buf.at(Index);
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

  CircBuf.push_back(1);
  CircBuf.push_back(2);
  CircBuf.push_back(3);
  CircBuf.push_back(4);
  CircBuf.push_back(5);

  std::cout << "Index 7: " << CircBuf.at(8) << std::endl;

  return 0;
}
