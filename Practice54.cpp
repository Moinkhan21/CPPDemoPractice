#include <iostream>
#include <numeric>  // For accumulate()
using namespace std;

/*
---------------------------------------------------------------
Function: isPossibleSolution
Purpose : Checks if it's possible to allocate books to M students
          such that no student reads more than 'sol' pages.
Params  :
    A   - array of book pages
    N   - number of books
    M   - number of students
    sol - current maximum number of pages allowed per student
Returns :
    true  - if allocation is possible
    false - otherwise
---------------------------------------------------------------
*/
bool isPossibleSolution(int A[], int N, int M, int sol) {
    int pageSum = 0;
    int studentCount = 1;

    for (int i = 0; i < N; i++) {
        // If any single book has more pages than sol, allocation is not possible
        if (A[i] > sol) return false;

        // Allocate book to a new student if adding it exceeds the solution limit
        if (pageSum + A[i] > sol) {
            studentCount++;      // Increase student count
            pageSum = A[i];      // Reset pages for new student

            // If students exceed M, allocation is not possible
            if (studentCount > M) return false;
        } else {
            pageSum += A[i];     // Accumulate pages for current student
        }
    }
    return true;
}

/*
---------------------------------------------------------------
Function: findPages
Purpose : Finds the minimum number of pages a student must read
          by allocating books such that the max number of pages
          read by a student is minimized.
Params  :
    A - array of book pages
    N - number of books
    M - number of students
Returns :
    Minimum number of pages that a student has to read if possible,
    otherwise -1 if allocation is not possible
---------------------------------------------------------------
*/
int findPages(int A[], int N, int M) {
    // If students are more than books, allocation is impossible
    if (M > N) return -1;

    int start = 0;
    int end = accumulate(A, A + N, 0); // Total number of pages
    int ans = -1;

    // Binary search to minimize the maximum number of pages per student
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossibleSolution(A, N, M, mid)) {
            ans = mid;        // Valid solution found
            end = mid - 1;    // Try to find a smaller value
        } else {
            start = mid + 1;  // Try to find a valid larger value
        }
    }
    return ans;
}

/*
---------------------------------------------------------------
Main Function
Purpose : Tests the book allocation logic with sample input
---------------------------------------------------------------
*/
int main() {
    // Sample array of pages in books
    int A[] = {12, 34, 67, 90};
    int N = sizeof(A) / sizeof(A[0]); // Number of books
    int M = 2;                        // Number of students

    // Call the function to find minimum pages
    int result = findPages(A, N, M);

    // Display the result
    if (result != -1)
        cout << "Minimum number of pages a student has to read: " << result << endl;
    else
        cout << "Allocation not possible!" << endl;

    return 0;
}
