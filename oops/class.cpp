#include <iostream>
using namespace std;

struct Person {
    string name;
    string email;
};

int main() {
    Person obj = {"shivanshu", "singhshivanshi@"}; // Object declaration
    Person obj2 = obj;
    obj2.name = "singh";
    cout << "Name: " << obj.name << ", Email: " << obj.email << endl;
    
    cout << "Name: " << obj2.name << ", Email: " << obj2.email << endl;
    return 0;
}
