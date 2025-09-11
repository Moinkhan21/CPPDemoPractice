#include <iostream>   // For input and output (cout, cin)
#include <vector>     // For using the vector container
using namespace std;

int main(){
    // Create a vector 'v' of size 10 (initially filled with default value 0)
    // Syntax: vector<dataType> name(size);
    vector<int> v(10);

    // Assign value 10 to the first element (index 0)
    // Note: vector supports random access using []
    v[0] = 10;

    // Print the first element of the vector
    cout << v[0] << endl;  // Output: 10

    return 0; // Successful program termination
}
