#include <iostream>

enum RequestType { TYPE_A, TYPE_B };

class Request {
private:
  RequestType type;

public:
  Request(RequestType type) : type(type) {}
  RequestType getType() const { return type; }
};

class Handler {
public:
  virtual void handleRequest(Request request) = 0;
  virtual void setNextHandler(Handler *nextHandler) = 0;
  virtual ~Handler() = default;
};

class ConcreteHandlerA : public Handler {
private:
  Handler *nextHandler = nullptr;

public:
  void handleRequest(Request request) override {
    if (request.getType() == TYPE_A) {
      std::cout << "ConcreteHandlerA handled the request" << std::endl;
    } else if (nextHandler != nullptr) {
      nextHandler->handleRequest(request);
    }
  }

  void setNextHandler(Handler *nextHandler) override {
    this->nextHandler = nextHandler;
  }
};

class ConcreteHandlerB : public Handler {
private:
  Handler *nextHandler = nullptr;

public:
  void handleRequest(Request request) override {
    if (request.getType() == TYPE_B) {
      std::cout << "ConcreteHandlerB handled the request" << std::endl;
    } else if (nextHandler != nullptr) {
      nextHandler->handleRequest(request);
    }
  }

  void setNextHandler(Handler *nextHandler) override {
    this->nextHandler = nextHandler;
  }
};

int main() {
  Handler *handlerA = new ConcreteHandlerA();
  Handler *handlerB = new ConcreteHandlerB();

  handlerA->setNextHandler(handlerB);

  Request requestA(TYPE_A);
  Request requestB(TYPE_B);

  handlerA->handleRequest(requestA);
  handlerA->handleRequest(requestB);

  delete handlerA;
  delete handlerB;
}
