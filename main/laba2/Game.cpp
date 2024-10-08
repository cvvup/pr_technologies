#include <iostream>
#include <string>

class GameObject {
private:
  int id;
  std::string name;
  int x;
  int y;

public:
  GameObject(int id, std::string name, int x, int y)
      : id(id), name(name), x(x), y(y) {}

  std::string getName() const { return name; }

  int getX() const { return x; }

  int getY() const { return y; }

  void setPosition(int newX, int newY) {
    x = newX;
    y = newY;
  }
};

class Unit : public GameObject {
private:
  float HP;
  bool alive;

public:
  Unit(int id, const std::string &name, int x, int y, float hp)
      : GameObject(id, name, x, y), HP(hp), alive(true) {}

  bool isAlive() const { return alive; }

  float getHP() const { return HP; }

  void receiveDamage(float damage) {
    if (alive) {
      HP -= damage;
      if (HP <= 0) {
        alive = false;
        std::cout << getName() << " died." << std::endl;
      } else {
        std::cout << getName() << " receives " << damage
                  << " damage. Health is now " << HP << std::endl;
      }
    }
  }
};

class Attacker {
public:
  virtual void attack(Unit &unit) = 0;
};

class Moveable {
public:
  virtual void move(int newX, int newY) = 0;
};

class Archer : public Unit, public Attacker, public Moveable {
public:
  Archer(int id, std::string name, int x, int y, float hp)
      : Unit(id, name, x, y, hp) {}

  void attack(Unit &unit) override {
    std::cout << getName() << " attacks " << unit.getName() << std::endl;
  }

  void move(int x, int y) override {
    setPosition(x, y);
    std::cout << getName() << " moves to (" << x << ", " << y << ")."
              << std::endl;
  }
};

class Building : public GameObject {
private:
  bool built;

public:
  Building(int id, const std::string &name, int x, int y)
      : GameObject(id, name, x, y), built(false) {}

  bool isBuilt() const { return built; }

  void build() { built = true; }
};

class Fort : public Building, public Attacker {
public:
  Fort(int id, const std::string &name, int x, int y)
      : Building(id, name, x, y) {}

  void attack(Unit &unit) {
    if (isBuilt()) {
      unit.receiveDamage(150);
      std::cout << getName() << " attacks " << unit.getName() << std::endl;
    } else {
      std::cout << getName() << " died from a cannon." << std::endl;
    }
  }
};

class MobileHome : public Building, public Moveable {
public:
  MobileHome(int id, const std::string &name, int x, int y)
      : Building(id, name, x, y) {}

  void move(int newX, int newY) {
    if (isBuilt()) {
      setPosition(newX, newY);
      std::cout << getName() << " moves to (" << newX << ", " << newY << ")."
                << std::endl;
    } else {
      std::cout << getName() << " is not built yet and cannot move."
                << std::endl;
    }
  }
};

int main() {
  Unit unit(1, "Vasya", 0, 0, 100);
  unit.receiveDamage(20);
  unit.receiveDamage(50);

  Fort fort(2, "Vasya", 0, 0);
  fort.attack(unit);

  MobileHome mobileHome(3, "Mobile Home", 0, 0);
  mobileHome.build();
  mobileHome.move(10, 10);

  return 0;
}
