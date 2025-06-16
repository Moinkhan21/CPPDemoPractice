#include <iostream>
#include <vector>
using namespace std;

int findUniqueElements(vector<int> arr){
    int ans = 0; // Initialize a counter for unique elements

    for(int i = 0; i < arr.size(); i++){
        ans = ans ^ arr[i]; // Use XOR operation to find unique elements
    }

    return ans; // Return the result of XOR, which is the unique element
}

int main(){

    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n; // Input the size of the vector from the user

    vector<int> arr(n); // Create a vector of size n
    cout << "Enter the elements of the vector: " << endl;

    //taking input from the user
    for(int i = 0; i < n; i++){
        cin >> arr[i]; // Store each element in the vector
    }

    int uniqueElements = findUniqueElements(arr); // Call the function to find unique elements

    cout << "Number of unique elements: " << uniqueElements << endl; // Output the number of unique elements

    int brr[] = {1, 3, 5, 7, 9};
    int sizeA = 5;
    int crr[] = {2, 4, 6, 8, 10};
    int sizeB = 5;

    vector<int> ans;
    
    //push all elements of arr into ans
    for(int i = 0; i < sizeA; i++){
        ans.push_back(brr[i]); // Add elements from arr to ans
    }

    //push all elements of brr into ans
    for(int i = 0; i < sizeB; i++){
        ans.push_back(crr[i]); // Add elements from brr to ans
    }

    //Printing ans
    cout << "Printing the ans array: " << endl;

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " "; // Output each element in the ans vector
    }

    return 0; // Return 0 to indicate successful execution
}