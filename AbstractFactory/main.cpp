#include <iostream>

using namespace std;

//Chair
//Button
class AbstractProductA{
public:
    virtual ~AbstractProductA(){};
    virtual std::string UsefulFunctionA() const = 0;
};

//Chair Modern
//Check Button
class ConcreteProductA1: public AbstractProductA{
public:
    std::string UsefulFunctionA() const override {
        return "The result of the product A1.";
    }
};

class ConcreteProductA2: public AbstractProductA{
public:
    std::string UsefulFunctionA() const override {
        return "The result of the product A2.";
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
