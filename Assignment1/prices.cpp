#include <iostream>

using namespace std;

int main() {
    int price;
    int sum = 0;
    cout << " Enter a price: ";
    cin >> price;
    while (price >= 0) {
        sum += price;
        cout << " Enter a price: ";
        cin >> price;
    }
    
    cout << "\n The total price is: " << sum << endl;
    return 0;
}