#include <memory>
#include <iostream>

class Base {
public:
    Base(int num): num(num) {};

    virtual void sayHello() {
        std::cout << "I'm Base #" << num << std::endl;
    }

    ~Base() {
        std::cout << "~Base #" << num << std::endl;
    }

protected:
    int num;
};

class Derived: public Base {
public:
    Derived(int num): Base(num) {}

    virtual void sayHello() {
        std::cout << "I'm Derived #" << num << std::endl;
    }

    ~Derived() {
        std::cout << "~Derived #" << num << std::endl;
    }
};
void testUnique() {
    std::cout << "=== testUnique begin ===" << std::endl;

    auto derived = std::make_unique<Derived>(1);
    derived->sayHello();

    std::unique_ptr<Base> base = std::move(derived);
    base->sayHello();


    std::cout << "=== testUnique end ===" << std::endl;
}

void testShared() {
    std::cout << "=== testShared begin ===" << std::endl;

    auto derived = std::make_shared<Derived>(1);
    derived->sayHello();

    auto base = std::static_pointer_cast<Base>(derived);
    base->sayHello();


    std::cout << "=== testShared end ===" << std::endl;
}


int main() {
    testUnique();
    testShared();
}
