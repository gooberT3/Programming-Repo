#include <iostream>

class FooClass
{
    private:
        std::string foo;
    public:
        FooClass()
        {
            foo = "I am from a private class";
        }
        void displayFoo()
        {
            std::cout << foo;
        }
};

int main()
{
    FooClass test;
    test.displayFoo();    

    return 0;
}
