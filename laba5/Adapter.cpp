#include <iostream>
#include <string>

class UserDataInterface {
public:
  virtual void getUserData(int UserID) = 0;
};

class UserLibrary {
public:
  std::string UserInfo(int UserID) {
    return "ID: " + std::to_string(UserID) + ", Name: Pasha, Age: 20";
  }
};

class UserDataAdapter : public UserDataInterface {
private:
  UserLibrary *userlibrary;

public:
  UserDataAdapter(UserLibrary *library) : userlibrary(library) {}

  void getUserData(int UserID) override {
    std::string UserInfo = userlibrary->UserInfo(UserID);
    std::cout << "User Data: " << UserInfo << std::endl;
  }
};

int main() {
  UserLibrary userlibrary;
  UserDataAdapter userDataAdapter(&userlibrary);
  userDataAdapter.getUserData(1);
}