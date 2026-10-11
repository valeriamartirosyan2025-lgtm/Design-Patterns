#include <iostream>
#include <string>
#include <memory>

using namespace std;

class House {
public:
    string foundation;
    string structure;
    string roof;

    void showSpecs() const {
        cout << "House with " << foundation << ", " << structure << ", and " << roof << ".\n";
    }
};

class HouseBuilder {
protected:
    unique_ptr<House> house;
public:
    HouseBuilder() { house = make_unique<House>(); }
    virtual void buildFoundation() = 0;
    virtual void buildStructure() = 0;
    virtual void buildRoof() = 0;
    virtual unique_ptr<House> getResult() { return std::move(house); }
    virtual ~HouseBuilder() = default;
};

class WoodenHouseBuilder : public HouseBuilder {
public:
    void buildFoundation() override { house->foundation = "Wooden Poles"; }
    void buildStructure() override { house->structure = "Wood Panels"; }
    void buildRoof() override { house->roof = "Wooden Shingles"; }
};

class Director {
public:
    unique_ptr<House> construct(HouseBuilder& builder) {
        builder.buildFoundation();
        builder.buildStructure();
        builder.buildRoof();
        return builder.getResult();
    }
};

int main() {
    Director director;
    WoodenHouseBuilder woodenBuilder;

    unique_ptr<House> house = director.construct(woodenBuilder);
    house->showSpecs();

    return 0;
}