#include <iostream>
#include <utility>
#include <vector>

class SortingStrategy {
public:
  virtual void sort(std::vector<int> &array) = 0;
};

class BubbleSortStrategy : public SortingStrategy {
public:
  void sort(std::vector<int> &array) override {
    int n = array.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (array[j] < array[i]) {
          std::swap(array[j], array[i]);
        }
      }
    }
  }
};

class InsertionSort : public SortingStrategy {
public:
  void sort(std::vector<int> &array) override {
    int i, j, key;
    for (int i = 0; i < array.size(); i++) {
      key = array[i];
      j = i - 1;
      while (j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j = j - 1;
      }
      array[j + 1] = key;
    }
  }
};

class Print {
public:
  void print(std::vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
      std::cout << array[i] << ' ';
    }
  }
};

class Sorter {
private:
  SortingStrategy *strategy;

public:
  void setStrategy(SortingStrategy *strategy) { this->strategy = strategy; }
  void sort(std::vector<int> &array) {
    if (strategy) {
      strategy->sort(array);
    }
  }
};

int main() {
  Sorter sorter;
  BubbleSortStrategy bubbleSort;
  BubbleSortStrategy InsertionSort;
  Print print;

  sorter.setStrategy(&bubbleSort);

  std::vector<int> array = {5, 6, 8, 4, 2};
  std::cout << "Before: ";
  print.print(array);

  sorter.sort(array);

  std::cout << std::endl << "After: ";
  print.print(array);

  sorter.setStrategy(&InsertionSort);

  std::vector<int> array2 = {1, 3, 2, 4, 5};
  std::cout << std::endl << "Before: ";
  print.print(array2);

  sorter.sort(array2);

  std::cout << std::endl << "After: ";
  print.print(array2);
}