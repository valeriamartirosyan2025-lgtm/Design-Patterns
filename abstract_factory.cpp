#include <iostream>
#include <memory>

using namespace std;

class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() = default;
};

class Checkbox {
public:
    virtual void paint() = 0;
    virtual ~Checkbox() = default;
};

class WinButton : public Button {
public:
    void paint() override { cout << "Rendering Windows Button.\n"; }
};

class WinCheckbox : public Checkbox {
public:
    void paint() override { cout << "Rendering Windows Checkbox.\n"; }
};

class GUIFactory {
public:
    virtual unique_ptr<Button> createButton() = 0;
    virtual unique_ptr<Checkbox> createCheckbox() = 0;
    virtual ~GUIFactory() = default;
};

class WinFactory : public GUIFactory {
public:
    unique_ptr<Button> createButton() override { return make_unique<WinButton>(); }
    unique_ptr<Checkbox> createCheckbox() override { return make_unique<WinCheckbox>(); }
};

int main() {
    unique_ptr<GUIFactory> factory = make_unique<WinFactory>();
    unique_ptr<Button> button = factory->createButton();
    unique_ptr<Checkbox> checkbox = factory->createCheckbox();

    button->paint();
    checkbox->paint();

    return 0;
}