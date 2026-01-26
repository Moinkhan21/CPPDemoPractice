#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    //Creation
    unordered_map<string, int> m;

    //Insertion
    pair<string, int> p = make_pair("Scorpio", 9);
    m.insert(p);

    pair<string, int> p1("Alto", 2);
    m.insert(p1);

    m["Fortuner"] = 10;

    //Access
    cout << m.at("Alto") << endl;
    cout << m.at("Scorpio") << endl;
    cout << m["Fortuner"] << endl;

    //Search OR Find
    cout << m.count("Alto") << endl;
    cout << m.count("Innova") << endl;
    if(m.find("Fortuner") != m.end()) {
        cout << "Fortuner is found" << endl;
    }
    else {
        cout << "Fortuner is not found" << endl;
    }

    cout << m.size() << endl;
    
    return 0;
}