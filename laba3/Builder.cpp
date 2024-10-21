#include <iostream>
#include <string>

class Salad {
private:
  std::string tomatoes;
  std::string sauce;

public:
  void setTomatoes(std::string &tomatoes) { this->tomatoes = tomatoes; }

  void setSauce(std::string &sauce) { this->sauce = sauce; }

  std::string toString() {
    return "Salad{tomatoes='" + tomatoes + "', dressing='" + sauce + "'}";
  }
};

class SaladBuilder {
public:
  virtual void buildTomatoes() = 0;
  virtual void buildSauce() = 0;
  virtual Salad getResult() = 0;
};

class TomatoSaladBuilder : public SaladBuilder {
private:
  Salad salad;

public:
  void buildTomatoes() override {
    std::string tomatoes = "томаты";
    salad.setTomatoes(tomatoes);
  }

  void buildSauce() override {
    std::string sauce = "мазик";
    salad.setSauce(sauce);
  }

  Salad getResult() override { return salad; }
};

class SaladDirector {
private:
  SaladBuilder *builder;

public:
  SaladDirector(SaladBuilder *builder) : builder(builder) {}

  void constructSalad() {
    builder->buildTomatoes();
    builder->buildSauce();
  }
};

int main() {
  TomatoSaladBuilder builder;
  SaladDirector director(&builder);

  director.constructSalad();
  Salad salad = builder.getResult();

  std::cout << salad.toString() << std::endl;

  return 0;
}
