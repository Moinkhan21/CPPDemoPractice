#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) {
    string result = "";
    string romanNumerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            result += romanNumerals[i];
            num -= values[i];
        }
    }
    return result;
}

int main(){
    int num = 1994;
    string roman = intToRoman(num);
    cout << "The Roman numeral for " << num << " is " << roman << endl;
    return 0;
}