#include <iostream>

using namespace std;


/*
Singleton is a creational design pattern that
This pattern ensure that a class has only one instance,
and provides a global access to this instance.
*/

class Singleton{

protected:
    Singleton(const std::string& value): value_(value){

    }

    static Singleton* singleton_;

    std::string value_;

public:
    //not cloneable.
    Singleton(Singleton &other) = delete;

    //not assignable
    void operator=(const Singleton &) = delete;

    static Singleton *GetInstance(const std::string& value);

    void doSomething()
    {
        std::cout << "Save Data..." + value_ << std::endl;
    }

    std::string value() const{
        return value_;
    }
};

Singleton* Singleton::singleton_ = nullptr;


Singleton* Singleton::GetInstance(const std::string& value)
{
    if(singleton_ == nullptr)
    {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}


int main()
{
    Singleton* mySingle = Singleton::GetInstance("NAME AND LASTNAME");

    mySingle->doSomething();

    return 0;
}
