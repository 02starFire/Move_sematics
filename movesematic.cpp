#include <iostream>
#include <utility>
#include <cstring>

class MyString {
public:
    // Move Constructor
    MyString(MyString&& other) noexcept : data(other.data) {
        other.data = nullptr; // Steal the data
    }

    // Regular Constructor
    MyString(const char* str) {
        std::cout << "Regular Constructor\n";
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

private:
    char* data;
    size_t size;
};

int main() {
    MyString regularString("hello babygirl!"); // Regular Constructor
    MyString movedString = std::move(regularString); // Move Constructor

    // regularString's data is nullptr after the move
    // movedString now owns the memory previously owned by regularString

    return 0;
}

