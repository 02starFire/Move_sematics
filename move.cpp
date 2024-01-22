#include <iostream>
#include <utility>
#include <vector>

class A {
public:
    A() = default;  // Added default constructor

    A(A&& other) noexcept : data(std::move(other.data)) {
        // Move constructor implementation
    }

    std::vector<int> Generate() {
        return data;  // Assuming 'data' is a member variable in your class A
    }

private:
    std::vector<int> data;
};

int main() {
    A obj1;  // Now uses the default constructor
    std::vector<int> result = obj1.Generate();

    A obj2 = std::move(obj1);

    return 0;
}

