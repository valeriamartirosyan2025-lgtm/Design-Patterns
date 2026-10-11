#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class FileSystemComponent {
public:
    virtual void display(int depth) const = 0;
    virtual ~FileSystemComponent() = default;
};

class File : public FileSystemComponent {
private:
    string name;
public:
    File(string n) : name(n) {}
    void display(int depth) const override {
        cout << string(depth, '-') << " File: " << name << endl;
    }
};

class Directory : public FileSystemComponent {
private:
    string name;
    vector<shared_ptr<FileSystemComponent>> children;
public:
    Directory(string n) : name(n) {}

    void add(shared_ptr<FileSystemComponent> component) {
        children.push_back(component);
    }

    void display(int depth) const override {
        cout << string(depth, '+') << " Directory: " << name << endl;
        for (const auto& child : children) {
            child->display(depth + 2);
        }
    }
};

int main() {
    auto root = make_shared<Directory>("RootFolder");
    auto file1 = make_shared<File>("document.txt");
    auto subDir = make_shared<Directory>("SubFolder");
    auto file2 = make_shared<File>("image.png");

    subDir->add(file2);
    root->add(file1);
    root->add(subDir);

    root->display(0);

    return 0;
}