#include <iostream>
#include <memory>

using namespace std;

class Button {
public:
    virtual void render() = 0;
    virtual ~Button() = default;
};

class WindowsButton : public Button {
public:
    void render() override {
        cout << "Rendering Windows style button.\n";
    }
};

class WebButton : public Button {
public:
    void render() override {
        cout << "Rendering Web style button.\n";
    }
};

class Dialog {
public:
    virtual unique_ptr<Button> createButton() = 0; // Factory Method

    void renderWindow() {
        unique_ptr<Button> btn = createButton();
        btn->render();
    }
    virtual ~Dialog() = default;
};

class WindowsDialog : public Dialog {
public:
    unique_ptr<Button> createButton() override {
        return make_unique<WindowsButton>();
    }
};

class WebDialog : public Dialog {
public:
    unique_ptr<Button> createButton() override {
        return make_unique<WebButton>();
    }
};

int main() {
    unique_ptr<Dialog> dialog = make_unique<WebDialog>();
    dialog->renderWindow();

    return 0;
}