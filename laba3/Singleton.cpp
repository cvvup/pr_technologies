#include <iostream>

class Singleton {
private:
  static Singleton *instance;

  Singleton() {}

  ~Singleton() {}

public:
  Singleton(const Singleton &) = delete;

  Singleton &operator=(const Singleton &) = delete;

  static Singleton *getInstance() {
    if (instance == nullptr) {
      instance = new Singleton();
    }
    return instance;
  }

  void someMethod() { std::cout << "Singleton!" << std::endl; }
};

Singleton *Singleton::instance = nullptr;

int main() {
  Singleton *singleton = Singleton::getInstance();
  singleton->someMethod();
}
