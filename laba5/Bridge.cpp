#include <iostream>
#include <string>

class Device {
public:
  virtual void print(std::string data) = 0;
};

class Monitor : public Device {
public:
  void print(std::string data) override {
    std::cout << "Displaying on monitor: " << std::endl << data << std::endl;
  }
};

class Printer : public Device {
public:
  void print(std::string data) override {
    std::cout << "Printing to paper: " << std::endl << data << std::endl;
  }
};

class Output {
protected:
  Device *device;

public:
  Output(Device *device) : device(device) {}
  virtual void render(std::string data) = 0;
};

class TextOutput : public Output {
public:
  TextOutput(Device *device) : Output(device) {}

  void render(std::string data) override { device->print("Text: " + data); }
};

class ImageOutput : public Output {
public:
  ImageOutput(Device *device) : Output(device) {}

  void render(std::string data) override {
    device->print("Image: [Binary data: " + data + "]");
  }
};

int main() {
  Device *monitor = new Monitor();
  Device *printer = new Printer();

  Output *textOnMonitor = new TextOutput(monitor);
  Output *textOnPrinter = new TextOutput(printer);

  textOnMonitor->render("Hello, world!");
  textOnPrinter->render("Hello, world!");

  Output *imageOnMonitor = new ImageOutput(monitor);
  imageOnMonitor->render("101010101");
}