#include <iostream>
#include <utility>
#include <cstring>

class MyString {

        public:
                MyString(MyString&& other) noexcept : data(other.data) {
                other.data = nullptr; //steal data
                }


        MyString(const char* str) {
                std::cout << "Regular Constructor\n"<<std::endl;
                size = strlen(str);
                data = new char[size + 1];
                strcpy(data,str);
        }

        ~MyString() {

        delete[] data;

        }

        private:
                char* data;
                size_t size;

};

int main() {
        MyString regularString("hello babygirl!");
        MyString movedString = std::move(regularString);

return 0;
}
