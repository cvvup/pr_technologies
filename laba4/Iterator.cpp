#include <iostream>
#include <stdexcept>

template <typename T> class Iterator {
public:
  virtual bool hasNext() = 0;
  virtual T next() = 0;
};

template <typename T> class ArrayIterator : public Iterator<T> {
private:
  T *items;
  int size;
  int position;

public:
  ArrayIterator(T *items, int size) : items(items), size(size), position(0) {}

  bool hasNext() override { return position < size; }

  T next() override {
    if (this->hasNext()) {
      return items[position++];
    }
    throw std::out_of_range("No more elements in the array.");
  }
};

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  ArrayIterator<int> iterator(arr, 5);

  while (iterator.hasNext()) {
    std::cout << iterator.next() << std::endl;
  }
}
