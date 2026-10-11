#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Prototype {
public:
    virtual unique_ptr<Prototype> clone() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Prototype() = default;
};

class ConcreteDocument : public Prototype {
private:
    string title;
    string content;
public:
    ConcreteDocument(string t, string c) : title(t), content(c) {}

    unique_ptr<Prototype> clone() const override {
        return make_unique<ConcreteDocument>(*this);
    }

    void printInfo() const override {
        cout << "Document Title: " << title << "\nContent: " << content << "\n\n";
    }
};

int main() {
    auto originalDoc = make_unique<ConcreteDocument>("Report Q3", "Financial data analysis...");
    originalDoc->printInfo();

    auto clonedDoc = originalDoc->clone();
    clonedDoc->printInfo();

    return 0;
}