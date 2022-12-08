#include <iostream>

class FooClass
{
    private:
        std::string foo;
        int num1,
            num2;
    public:
        FooClass()
        {
            foo = "I am from a private class";
            num1 = 1;
            num2 = 1;
        }
        void displayFoo()
        {
            std::cout << foo;
        }
        void addNums()
        {
            std::cout << num1 + num2 << std::endl;
        }
};

int main()
{
    FooClass test;
    test.displayFoo();    
    test.addNums();

    return 0;
}
