#include <iostream>
using namespace std;

class MathUtility {
public:
    // Static data member
    static int counter;

    // Static method to add two numbers
    static int add(int a, int b) {
        counter++; // Modify the static member
        return a + b;
    }

    // Non-static method to display the counter
    void showCounter() const {
        cout << "Counter: " << counter << endl;
    }
};

// Define and initialize the static member outside the class
int MathUtility::counter = 0;

int main() {
    // Call the static method without creating an object
    cout << "5 + 3 = " << MathUtility::add(5, 3) << endl;
    cout << "10 + 7 = " << MathUtility::add(10, 7) << endl;

    // Use a class instance to access the static member
    MathUtility mathObj;
    mathObj.add(8,9);
    mathObj.showCounter();  // Displays the current value of counter

    return 0;
}
