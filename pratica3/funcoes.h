#include <cstring>

using namespace std;

namespace func {
  template <class T>
  void trocar(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;
  }

  template <class T>
  int maximo(const T a, const T b) {
    return (a > b) ? a : b;
  }

  template <class T>
  int minimo(const T a, const T b) {
    return (a < b) ? a : b;
  }

  string maximo(const char * a, const char * b) {
    int res = strcmp(a, b);
    return (res > 0) ? a : b;
  }

  string minimo(const char * a, const char * b) {
    int res = strcmp(a, b);
    return (res < 0) ? a : b;
  }
}
