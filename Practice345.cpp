#include <iostream>
#include <queue>
using namespace std;

int getKthGreatestElement(int arr[], int n, int k) {
    //Create min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    ///Insert initial K elements of array
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    //For remaining elements, push only if they are greater than top
    for(int i = k; i < n; i++) {
        int element = arr[i];
        if(element > pq.top()) {
            pq.pop();
            pq.push(element);
        }
    }
    int ans2 = pq.top();
    return ans2;
}

int getKthSmallestElement(int arr[], int n, int k) {
    //Create max heap
    priority_queue<int> pq;

    ///Insert initial K elements of array
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    //For remaining elements, push only if they are less than top
    for(int i = k; i < n; i++) {
        int element = arr[i];
        if(element < pq.top()) {
            pq.pop();
            pq.push(element);
        }
    }
    int ans1 = pq.top();
    return ans1;
}

int main() {
    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 2;
    int ans1 = getKthSmallestElement(arr, n, k);

    cout << "Ans is : " << ans1 << endl;

    int ans2 = getKthGreatestElement(arr, n, k);

    cout << "Ans is : " << ans2 << endl;

    return 0;
}