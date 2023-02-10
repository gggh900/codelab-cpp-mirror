#include <memory>
#include <utility>
#include <functional>
#include <iostream>

template <typename T> class lazy_ptr {
 public:
  lazy_ptr() {}

  explicit lazy_ptr(std::function<T*()> Constructor) { Init(Constructor); }
  lazy_ptr(lazy_ptr&& rhs) {
    obj = std::move(rhs.obj);
    func = std::move(rhs.func);
  }

  lazy_ptr& operator=(lazy_ptr&& rhs) {
    obj = std::move(rhs.obj);
    func = std::move(rhs.func);
  }

  lazy_ptr(lazy_ptr&) = delete;
  lazy_ptr& operator=(lazy_ptr&) = delete;

  void reset(std::function<T*()> Constructor = nullptr) {
    std::cout << "GG:lazy_ptr reset(std::function<T*()> Constructor = nullptr) (replacing function with new func) " << &Constructor << std::endl;
    obj.reset();
    func = Constructor;
  }

  void reset(T* ptr) {
    std::cout << "GG:lazy_ptr reset(T* ptr) (resetting func to null)" << std::endl;
    obj.reset(ptr);
    func = nullptr;
  }
  bool operator==(T* rhs) const { return obj.get() == rhs; }
  bool operator!=(T* rhs) const { return obj.get() != rhs; }

  const std::unique_ptr<T>& operator->() const {
    //make(true);
    assert(obj != nullptr && "Null dereference through lazy_ptr.");
    return obj;
  }

  std::unique_ptr<T>& operator*() {
    //make(true);
    return obj;
  }

  const std::unique_ptr<T>& operator*() const {
    //make(true);
    return obj;
  }

  /*
   * Ensures that the object is created or is being created.
   * This is useful when early construction of the object is required.
   */
  void touch() const { 
     //make(false); 
  }

  // Tells if the lazy object exists or not.
  /*
  bool empty() const {
    std::atomic_thread_fence(std::memory_order_acquire);
    return obj == nullptr;
  }*/
  std::unique_ptr<T> getObj() { return obj; }
  std::function<T*(void)> getFunc() { return func; }

 private:
  mutable std::unique_ptr<T> obj;
  mutable std::function<T*(void)> func;

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

class c1 {
private:
    lazy_ptr<c1> c1_lazy[3];
public:
    c1() {};
    void c1_f1(void);    
};

