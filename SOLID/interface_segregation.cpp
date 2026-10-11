#include <iostream>

using namespace std;

class IWorkable {
public:
    virtual void work() = 0;
    virtual ~IWorkable() = default;
};

class IEatable {
public:
    virtual void eat() = 0;
    virtual ~IEatable() = default;
};

class Human : public IWorkable, public IEatable {
public:
    void work() override {
        cout << "Human is working hard.\n";
    }
    void eat() override {
        cout << "Human is having lunch.\n";
    }
};

class Robot : public IWorkable {
public:
    void work() override {
        cout << "Robot is executing assembly tasks.\n";
    }
   
};

int main() {
    Human worker;
    Robot bot;

    worker.work();
    worker.eat();

    bot.work();

    return 0;
}