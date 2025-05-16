#include <iostream>
#include <vector>

/// faster circular buffer implementation using a dynamic array
template <class T> class fast_circ_buf {
public:
  explicit fast_circ_buf(int Size) : m_bufsize(Size), m_occupation(0), m_override(false){};

  // adds one element to the circular buffer
  // returns false once the buffer is full, otherwise returns true
  // except if the override is set, then it'll always return true and override
  // elements
  bool push_back(T Element) {
    bool success = false;
    // there is no space anymore
    if (m_occupation >= m_bufsize) {
      // override flag is set, so start overwriting
      if (m_override) {
        m_buf.at(m_currentelementindex) = Element;
        m_currentelementindex++;
        success = true;
      }else {
        success = false;
      }
    }else {
      // there is still space for a new element
      m_buf.push_back(Element);
      m_occupation++;
      success = true;
    }
    return success;
  };

  // returns the element at the current index
  // index wraps around
  T at(int Index) {
    while (Index >= m_bufsize) {
      Index = m_bufsize % Index;
    }
    return m_buf.at(Index);
  }

  // sets whether push_back should simply override the elements
  // when the buffer is full
  void set_override(bool override) { m_override = override; };

  // clears internal data array
  /// sort of a pseudo clear, simply releases all objects to be overwritten
  void clear() {
    m_occupation = 0;
  };

  // allocate memory based on new size
  void resize(int size) {
    // new buffer size so that .at works correctly
    m_bufsize = size;
  };

  // returns the current circbuf size
  int size(){
    return m_bufsize;
  }

private:
  std::vector<T> m_buf;
  int m_bufsize; // semi constant size that can't be changed but with a call to .resize; indexed at 1
  int m_occupation;
  bool m_override;
  int m_currentelementindex = 0;
};

int main() {
  int success = 0;

  fast_circ_buf<int> CircBuf(5);
  int testval = 100;

  CircBuf.push_back(testval);
  CircBuf.push_back(2);
  CircBuf.push_back(3);
  CircBuf.push_back(4);
  CircBuf.push_back(5);

  // test for wraparound index
  if (CircBuf.at(5) == 100) {
    printf("[=]SUCCESS: Wraparound Index test\n");
    success &= 0;
  }else {
    printf("[=]FAILURE: Wraparound Index test\n");
    success &= 1;
  }

  // test for overwritten value
  CircBuf.set_override(true);
  if (CircBuf.push_back(1337)) {
    if (CircBuf.at(0) == 1337) {
      printf("[=]SUCCESS: Override value test\n");
      success &= 0;
    }else {
      printf("[=]FAILURE: Override value test\n");
      success &= 1;
    }
  }

  // disable override flag again
  CircBuf.set_override(false);

  // test resize
  CircBuf.resize(6);
  CircBuf.push_back(10);

  if (CircBuf.size() == 6) {
    if (CircBuf.at(5) == 10) {
      printf("[=]SUCCESS: resize test\n");
      success &= 0;
    }else {
      printf("[=]FAILURE: resize test\n");
      success &= 1;
    }
  }

  return success;
}
