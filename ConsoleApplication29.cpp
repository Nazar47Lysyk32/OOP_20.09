#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Container {

public:
    // Додавання елемента до контейнера
    void add(const T& item) {
        items_.push_back(item);
    }

    // Видалення елемента з контейнера за індексом
    void remove(int index) {
        if (index >= 0 && index < items_.size()) {
            items_.erase(items_.begin() + index);
        }
    }

    // Пошук елемента у контейнері
    int find(const T& item) const {
        for (int i = 0; i < items_.size(); ++i) {
            if (items_[i] == item) {
                return i;
            }
        }
        return -1; // Повертає -1, якщо елемент не знайдено
    }

    // Сортування контейнера
    void sort() {
        for (int i = 0; i < items_.size() - 1; ++i) {
            for (int j = 0; j < items_.size() - i - 1; ++j) {
                if (items_[j] > items_[j + 1]) {
                    T temp = items_[j];
                    items_[j] = items_[j + 1];
                    items_[j + 1] = temp;
                }
            }
        }
    }

    // Виведення всіх елементів контейнера
    void display() const {
        for (const T& item : items_) {
            cout << item << " ";
        }
        cout << endl;
    }

private:
    vector<T> items_;
};

int main() {
    Container<int> intContainer;
    intContainer.add(5);
    intContainer.add(2);
    intContainer.add(8);
    intContainer.add(1);

    cout << "Original container: ";
    intContainer.display();

    intContainer.sort();
    cout << "Sorted container: ";
    intContainer.display();

    intContainer.remove(1);
    cout << "Container after removing an element: ";
    intContainer.display();

    int searchValue = 8;
    int foundIndex = intContainer.find(searchValue);
    if (foundIndex != -1) {
        cout << searchValue << " found at index " << foundIndex << endl;
    }
    else {
        cout << searchValue << " not found in the container." << endl;
    }

    Container<string> stringContainer;
    stringContainer.add("apple");
    stringContainer.add("banana");
    stringContainer.add("cherry");

    cout << "String container: ";
    stringContainer.display();

    stringContainer.sort();
    cout << "Sorted string container: ";
    stringContainer.display();

    return 0;
}
