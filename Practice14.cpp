#include <iostream> 
#include <vector>
using namespace std;

int main() {

    vector<int> arr;

    int ans = (sizeof(arr) / sizeof(int)); // Calculate the size of the vector in bytes and divide by size of int
    cout << ans << endl; // Output the size of the vector

    cout << arr.size() << endl; // Output the size of the vector using the size() method
    cout << arr.capacity() << endl; // Output the capacity of the vector

    return 0; // Return 0 to indicate successful execution
}