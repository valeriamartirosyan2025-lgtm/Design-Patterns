#include <iostream>
#include <string>
#include <memory>

using namespace std;

class ITarget {
public:
    virtual void request(const string& message) = 0;
    virtual ~ITarget() = default;
};

class LegacyService {
public:
    void oldSpecificRequest(const char* data) {
        cout << "[Legacy Service] Processing old data format: " << data << endl;
    }
};

class ServiceAdapter : public ITarget {
private:
    unique_ptr<LegacyService> legacyService;
public:
    ServiceAdapter(unique_ptr<LegacyService> service) : legacyService(std::move(service)) {}

    void request(const string& message) override {
        legacyService->oldSpecificRequest(message.c_str());
    }
};

int main() {
    auto legacy = make_unique<LegacyService>();
    unique_ptr<ITarget> adapter = make_unique<ServiceAdapter>(std::move(legacy));

    adapter->request("Hello via Adapter pattern!");

    return 0;
}