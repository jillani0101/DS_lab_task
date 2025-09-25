#include<iostream>
using namespace std;

// Function to generate secret code (factorial calculation)
int generateCode(int n) {
    if (n == 0) return 1;
    int result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int (*codePtr)(int);
    
    codePtr = generateCode;
    
    int number;
    cout << "Enter secret number: ";
    cin >> number;
    
    int secretCode = codePtr(number);
    
    cout << "Your secret code is: " << secretCode << endl;
    
    return 0;
}
