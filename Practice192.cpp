#include <iostream>
using namespace std;

// ======================================================================
// MACROS
// ----------------------------------------------------------------------
// Macros are preprocessor directives.
// They are replaced BEFORE compilation.
//
// IMPORTANT:
//   • No type checking
//   • Faster (no function call overhead)
//   • Can be dangerous if not used carefully
// ======================================================================

// Constant macro
#define PI 3.14

// Function-like macro
#define MAXX(x, y) ( (x) > (y) ? (x) : (y) )

// ======================================================================
// FUNCTION: circleArea()
// ----------------------------------------------------------------------
// PURPOSE:
//   Calculates area of a circle using macro PI
// ======================================================================
float circleArea(float r) {
    return PI * r * r;
}

// ======================================================================
// FUNCTION: circlePerimeter()
// ----------------------------------------------------------------------
// PURPOSE:
//   Calculates perimeter of a circle
// ======================================================================
float circlePerimeter(float r) {
    return 2 * PI * r;
}

// ======================================================================
// FUNCTION: fun()
// ----------------------------------------------------------------------
// PURPOSE:
//   Demonstrates macro usage
// ======================================================================
void fun() {
    int x = 6;
    int b = 17;

    int c = MAXX(x, b);  // Expands to: (x > b ? x : b)
}

// ======================================================================
// FUNCTION: fun2()
// ======================================================================
void fun2() {
    int a = 6;
    int b = 17;

    int c = MAXX(a, b);
}

// ======================================================================
// FUNCTION: fun3()
// ======================================================================
void fun3() {
    int x = 6;
    int y = 17;

    int c = MAXX(x, y);
}

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    cout << "Area: " << circleArea(65.4) << endl;
    cout << "Perimeter: " << circlePerimeter(65.4) << endl;

    return 0;
}