#include <iostream>
#include <string>

class Document {
public:
  virtual void display() = 0;
};

class RealDocument : public Document {
private:
  std::string filename;

public:
  RealDocument(const std::string &filename) : filename(filename) {
    loadDocument();
  }
  void loadDocument() {
    std::cout << "Uploading a document: " << filename << std::endl;
  }
  void display() override {
    std::cout << "Displaying a document: " << filename << std::endl;
  }
};

class DocumentProxy : public Document {
private:
  std::string filename;
  std::string userRole;
  RealDocument* realdoc;

public:
  DocumentProxy(const std::string &filename, const std::string &userRole)
      : filename(filename), userRole(userRole), realdoc(nullptr) {}

  bool hasAccess() { return userRole == "admin"; }

  void display() override {
    if (hasAccess()) {
      if (realdoc == nullptr) {
        realdoc = new RealDocument(filename);
      }
      realdoc->display();
    } else {
      std::cout << "You are not an administrator." << std::endl;
    }
  }
};

int main() {
  std::string userRole = "admin";
  DocumentProxy document("secter.txt", userRole);
  std::cout << userRole << ':' << std::endl;
  document.display();

  std::string userRole2 = "Masha";
  DocumentProxy document2("secter.txt", userRole2);
  std::cout << userRole2 << ':' << std::endl;
  document2.display();
}
