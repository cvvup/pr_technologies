#include <iostream>

class Button {
public:
  virtual void paint() = 0;
  virtual ~Button() {}
};

class WindowsButton : public Button {
public:
  void paint() override {
    std::cout << "You have created a Windows button." << std::endl;
  }
};

class MacButton : public Button {
public:
  void paint() override {
    std::cout << "You have created a Mac button." << std::endl;
  }
};

class Checkbox {
public:
  virtual void paint() = 0;
  virtual ~Checkbox() {}
};

class WindowsCheckbox : public Checkbox {
public:
  void paint() override {
    std::cout << "You have created a Windows checkbox." << std::endl;
  }
};

class MacCheckbox : public Checkbox {
public:
  void paint() override {
    std::cout << "You have created a Mac checkbox." << std::endl;
  }
};

class GUIFactory {
public:
  virtual Button *createButton() = 0;
  virtual Checkbox *createCheckbox() = 0;
  virtual ~GUIFactory() {}
};

class WindowsFactory : public GUIFactory {
public:
  Button *createButton() override { return new WindowsButton(); }

  Checkbox *createCheckbox() override { return new WindowsCheckbox(); }
};

class MacFactory : public GUIFactory {
public:
  Button *createButton() override { return new MacButton(); }

  Checkbox *createCheckbox() override { return new MacCheckbox(); }
};

class Application {
private:
  Button *button;
  Checkbox *checkbox;

public:
  Application(GUIFactory *factory) {
    button = factory->createButton();
    checkbox = factory->createCheckbox();
  }

  ~Application() {
    delete button;
    delete checkbox;
  }

  void paint() {
    button->paint();
    checkbox->paint();
  }
};

int main() {
  GUIFactory *windowsFactory = new WindowsFactory();
  Application app1(windowsFactory);
  app1.paint();
  delete windowsFactory;

  GUIFactory *macFactory = new MacFactory();
  Application app2(macFactory);
  app2.paint();
  delete macFactory;
}
