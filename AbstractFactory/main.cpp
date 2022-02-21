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
//Window Button
class ConcreteProductA1: public AbstractProductA{
public:
    std::string UsefulFunctionA() const override {
        return "The result of the product A1.";
    }
};

//Chair Vintage
//Linux Button
class ConcreteProductA2: public AbstractProductA{
public:
    std::string UsefulFunctionA() const override {
        return "The result of the product A2.";
    }
};

//Table
//CheckBox
class AbstractProductB{
public:
    virtual ~AbstractProductB(){};
    virtual std::string UsefulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};


//Table Modern
//Window CheckBox
class ConcreteProductB1: public AbstractProductB{
public:
    std::string UsefulFunctionB() const override{
        return "The result of the product B1.";
    }

    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override{
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B1 colloborating with ( " + result + " )";
    }

};

//Table Vintage
//Linux CheckBox
class ConcreteProductB2: public AbstractProductB{
public:
    std::string UsefulFunctionB() const override{
        return "The result of the product B2.";
    }

    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override{
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B1 colloborating with ( " + result + " )";
    }

};

//GUI Factory
class AbstractFactory{
public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

//Window Factory
class ConcreteFactory1: public AbstractFactory{
public:
    AbstractProductA *CreateProductA() const override{
        return new ConcreteProductA1();
    }

    AbstractProductB *CreateProductB() const override{
        return new ConcreteProductB1();
    }

};

//Linux Factory
class ConcreteFactory2: public AbstractFactory{
public:
    AbstractProductA *CreateProductA() const override{
        return new ConcreteProductA2();
    }

    AbstractProductB *CreateProductB() const override{
        return new ConcreteProductB2();
    }

};

//Recibe una GUI Factory
//Application
void ClientCode(const AbstractFactory &factory){
    const AbstractProductA *product_a = factory.CreateProductA();
    const AbstractProductB *product_b = factory.CreateProductB();

    std::cout << product_a->UsefulFunctionA() << "\n";
    std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";

    delete product_a;
    delete product_b;
}

int main()
{
    cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1 *f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;

    cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2 *f2 = new ConcreteFactory2();
    ClientCode(*f2);
    delete f2;

    return 0;
}
