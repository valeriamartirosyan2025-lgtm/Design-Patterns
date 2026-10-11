#include <iostream>
#include <memory>

using namespace std;

class ISwitchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~ISwitchable() = default;
};

class LightBulb : public ISwitchable {
public:
    void turnOn() override {
        cout << "LightBulb is ON.\n";
    }
    void turnOff() override {
        cout << "LightBulb is OFF.\n";
    }
};

class Switch {
private:
    ISwitchable& device;
    bool isOn;
public:
    Switch(ISwitchable& dev) : device(dev), isOn(false) {}

    void press() {
        if (isOn) {
            device.turnOff();
            isOn = false;
        }
        else {
            device.turnOn();
            isOn = true;
        }
    }
};

int main() {
    auto bulb = make_unique<LightBulb>();
    Switch lightSwitch(*bulb);

    lightSwitch.press(); 
    lightSwitch.press(); ?

    return 0;
}