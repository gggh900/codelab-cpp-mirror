//https://www.codeproject.com/Articles/682455/Generic-Lazy-Evaluation-in-Cplusplus
#include <iostream>
#include <math.h>
using namespace std;

#define LAZY_EVAL 0
#define LAZY_EVAL_PRECOMPUTE_ONLY 1
#if LAZY_EVAL == 0

class vector {
  private:
    float _x, _y;
  public:
    vector(float x, float y) : _x(x), _y(y) { }
    float  get_x() const { return _x; }
    float  get_y() const { return _y; } 
    float  get_length() const { return sqrt(_x * _x + _y * _y); }
    //vector get_unit() const { return *this / get_length(); }
    // Some operator overloading for vector computations.
};   

#else // LAZY_EVAL
#if LAZY_EVAL_PRECOMPUTE_ONLY == 1
class vector {
  private:
    float _x, _y;
    float _length; 
    vector _unit; 
    void precompute() {
      _length = sqrtf(_x * _x + _y * _y);
      _unit = *this / _length; 
    }  
  public: 
    vector(float x, float y) : _x(x), _y(y) {
      precompute(); 
    }
    float   get_x() const { return _x; }
    float   get_y() const { return _y; }
    float   get_length() const { return _length; }
    vector& get_unit() const { return _unit; }
    // Some operator overloading for vector computations.
}; 
#else  // LAZY_EVAL_PRECOMPUT_ONLY
template<typename T>
class lazy {
  public:
    lazy() : m_initiator(default_initiator), m_initialized(false) { }
    lazy(std::function<T()> initiator) : m_initiator(initiator), m_initialized(false) { }
    T& getValue() {
      if (!m_initialized) {
        m_value = m_initiator();
        m_initialized = true;
      }
      return m_value;
    }
    operator T() {
      return getValue();
    }
    T& operator* () {
      return getValue();
    }
    lazy<T>& operator= (const lazy<T>& other) {
      m_initiator   = other.m_initiator;
      m_initialized = false;
      return *this;
    }
  private:
    static T default_initiator() {
      throw std::runtime_error("No lazy evaluator given.");
    }
    std::function<T()> m_initiator;
    T    m_value;
    bool m_initialized;
}; 

class vector {
  private:
    float _x, _y;
    lazy<float>  _length; 
    lazy<vector> _unit; 
    void initialize() {
      _length = lazy<float>([this]() { return sqrtf(_x * _x + _y * _y); });
      _unit   = lazy<vector>([this]() { return *this / _length; });
    }  
  public: 
    vector(float x, float y) : _x(x), _y(y) {
      initialize(); 
    }
    float   get_x() const { return _x; }
    float   get_y() const { return _y; }
    float   get_length()  { return *_length; }
    vector& get_unit()    { return *_unit; }
    // Some operator overloading for vector computations.
};    
#endif // LAZY_EVAL_PRECOMPUTE_ONLY
#endif // LAZY_EVAL

int main() {
#if LAZY_EVAL == 1
    auto pi        = lazy<float>([]() { return 3.141592; });
#else
    auto pi = vector(3,3);
    //auto area = pi * r * 2;
    //auto perimeter = pi * 2 * r;
#endif
    //cout << "area/perimeter: " << area << "," << perimeter << endl;
    cout << "pi: " << pi.get_length() << endl;
}
