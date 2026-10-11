#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string name;
    string email;
public:
    User(string n, string e) : name(n), email(e) {}

    string getName() const { return name; }
    string getEmail() const { return email; }
};

class UserRepository {
public:
    void saveToDatabase(const User& user) {
        cout << "[DB] Saving user " << user.getName() << " (" << user.getEmail() << ") to database...\n";
    }
};

class UserReportGenerator {
public:
    void printReport(const User& user) {
        cout << "[Report] Generating user report for: " << user.getName() << "\n";
    }
};

int main() {
    User user("Anna", "anna@example.com");

    UserRepository repo;
    repo.saveToDatabase(user);

    UserReportGenerator reporter;
    reporter.printReport(user);

    return 0;
}