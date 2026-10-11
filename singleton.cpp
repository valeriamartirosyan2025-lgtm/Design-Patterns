#include <iostream>
#include <string>

using namespace std;

class Database {
private:
   
    Database() {
        cout << "Database connected.\n";
    }

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

public:
    
    static Database& getInstance() {
        static Database instance; 
        return instance;
    }

    void executeQuery(const string& query) {
        cout << "Executing: " << query << endl;
    }
};

int main() {
   
    Database& db1 = Database::getInstance();
    db1.executeQuery("SELECT * FROM Users;");

    Database& db2 = Database::getInstance();
    db2.executeQuery("SELECT * FROM Products;");

    cout << "Address 1: " << &db1 << endl;
    cout << "Address 2: " << &db2 << endl;

    return 0;
}