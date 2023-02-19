#include <memory>
#include <utility>
#include <functional>
#include <iostream>
#include <cassert>
#define DEBUG_L2 0
template <typename T> class lazy_ptr {
 private:
 public:
  mutable std::unique_ptr<T> obj;
  mutable std::function<T*(void)> func;
  lazy_ptr() {}

  explicit lazy_ptr(std::function<T*()> Constructor) { Init(Constructor); }
  lazy_ptr(lazy_ptr&& rhs) {
    std::cout << " L1: lazy_ptr: explicit constructor entered." << std::endl;
    obj = std::move(rhs.obj);
    func = std::move(rhs.func);
  }

  lazy_ptr& operator=(lazy_ptr&& rhs) {
    std::cout << " L1: lazy_ptr: operator=() entered..." << std::endl;
    obj = std::move(rhs.obj);
    func = std::move(rhs.func);
  }

  lazy_ptr(lazy_ptr&) = delete;
  lazy_ptr& operator=(lazy_ptr&) = delete;

  void reset(std::function<T*()> Constructor = nullptr) {
    std::cout << " L1: lazy_ptr reset(std::function<T*()> Constructor = nullptr) (replacing function with new func) " << &Constructor << std::endl;

    //std::cout << "obj: " << obj << ", func: " << func << std::endl;
    //obj.reset(&Constructor);
    obj.reset();
    func = Constructor;
  }

  void print_state() {
    std::cout << "obj.get():  "  << obj.get() << ", func: " << func.target_type().name() << std::endl;
  }
  void reset(T* ptr) {
    std::cout << " L1: lazy_ptr reset(T* ptr) (resetting func to null)" << std::endl;
    obj.reset(ptr);
    func = nullptr;
  }

  void operator() () const {
    std::cout << " L1: lazy_ptr: operator() function override entered..." << std::endl;
  }

  bool operator==(T* rhs) const { 
    std::cout << " L1: lazy_ptr: operator==() entered..." << std::endl;
    return obj.get() == rhs; 
  }
  bool operator!=(T* rhs) const { 
    return obj.get() != rhs; 
    std::cout << " L1: lazy_ptr: operator!=() entered..." << std::endl;
  }

  const std::unique_ptr<T>& operator->() const {
    //make(true);
    #if DEBUG_L2 == 1
    std::cout << std::endl << "  L2: lazy_ptr: operator->() entered..." << std::endl;
    #endif
    assert(obj != nullptr && "Null dereference through lazy_ptr.");
    return obj;
  }

  std::unique_ptr<T>& operator*() {
    #if DEBUG_L2 == 1
    std::cout << std::endl << "  L2: lazy_ptr: operator* entered..." << std::endl;
    #endif
    //make(true);
    return obj;
  }

  const std::unique_ptr<T>& operator*() const {
    std::cout << " L1: lazy_ptr: const...operator*() entered..." << std::endl;
    //make(true);
    return obj;
  }

  /*
   * Ensures that the object is created or is being created.
   * This is useful when early construction of the object is required.
   */
  void touch() const { 
    std::cout << " L1: lazy_ptr: touch() entered..." << std::endl;
     //make(false); 
  }

  // Tells if the lazy object exists or not.
  /*
  bool empty() const {
    std::atomic_thread_fence(std::memory_order_acquire);
    return obj == nullptr;
  }*/
  std::unique_ptr<T> getObj() { 
    std::cout << " L1: lazy_ptr: getObj() entered..." << std::endl;
    return obj; 
  }
  std::function<T*(void)> getFunc() { 
    std::cout << " L1: lazy_ptr: getFunc() entered..." << std::endl;
    return func; 
  }

  // Separated from make to improve inlining.
  /*
  void make_body(bool block) const {
    if (block) {
      lock.Acquire();
    } else if (!lock.Try()) {
      return;
    }
    MAKE_SCOPE_GUARD([&]() { lock.Release(); });
    if (func == nullptr) return;
    T* ptr = func();
    obj.reset(ptr);
    std::atomic_thread_fence(std::memory_order_release);
    func = nullptr;
  }

  __forceinline void make(bool block) const {
    if (!created()) {
      make_body(block);
    }
  }
   */
};

class q1 {
private:
public:
    void operator() () const {
        std::cout << "  q1: operator() function override entered..." << std::endl;
    }

    void print_q1() { 
        std::cout << "  q1: print_q1() entered..." << std::endl; 
    }
    int * q1a;
};

class c1 {
private:
    lazy_ptr<q1> c1_q1[3];
public:

    c1() { std::cout << "c1::c1() constructor entered..." << std::endl; }
    //void c1_f1(void) { std::cout << "c1::f1() entered... " << std::endl; }
    void c1_f1(void);
};

