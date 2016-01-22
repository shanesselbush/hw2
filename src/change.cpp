#include "eecs230.h"

// Reads denominations until 0 and returns as a vector (without 0).
//
// Example:
//
//   - User inputs "4 9 17 0\n", returns { 4, 9, 17 }
//
vector<int> read_denominations() {
    cout<< "enter coin denominations (0 when done)" << "\n";
    vector<int> result;
    while (true) {
        int denominations;
        cin >> denominations;
        if (!cin)error("could not read denominations");
        if (denominations == 0) break;
        result.push_back(denominations);
    }
    return result;
}

// Reads an int from the user after prompting for the amount to make
// change for. Calls error on read error.
int read_amount() {
    int amount;
    cout << "enter value you want to make change for" << "\n";
    cin >> amount;
    if (!cin) error("Could not read amount");
    return amount;
}

// Computes change for the given denominations and amount. Assumes that
// `denominations` is sorted in decreasing order, so that it can try the
// amounts in order. The resulting vector contains the count for each coin
// in `denominations` in the same order.
//
// Examples:
//
//   - make_change({25, 10, 5, 1}, 97) == {3, 2, 0, 2})
//
//   - make_change({25, 5, 1}, 97)     == {3, 4, 2})
//
//   - make_change({2}, 3) calls error("Could not make change.")
//
vector<int> make_change(vector<int> denominations, int amount) {
    vector<int> result;
    int change;
    for (int d: denominations) {
        change = amount / d;
        amount = amount % d;
        result.push_back(change);
    }
    if (amount != 0) error("could not make change");

    return result;

}

// Given the vector of denominations and vector of change, prints
// how many of each denomination to use.
//
// Example:
//
//  - print_change({10, 5, 1}, {3, 0, 8}) prints
//
//        Change is:
//        3 coin(s) of denomination 10
//        0 coin(s) of denomination 5
//        8 coin(s) of denomination 1
void print_change(vector<int> denominations, vector<int> change){
    cout << "Change is:" << "\n";
    for (int i=0;i<change.size();i++){
        cout << change[i] << " coin(s) of denomination " << denominations[i] << "\n";
    }

}

int main()
try {
    auto denoms = read_denominations();
    sort(denoms, [=](double x, double y) { return x > y; });
    auto amount = read_amount();
    auto change = make_change(denoms, amount);
    print_change(denoms, change);
}
catch (runtime_error &e) {
    cerr << "runtime error: " << e.what() << '\n';
    return 1;
}

