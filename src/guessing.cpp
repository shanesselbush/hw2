#include "eecs230.h"

static const string yes{"yes"};
static const string no{"no"};

void error(string s) {
    throw runtime_error(s);
}

int main()
try {
    cout <<"Think of a number between 1 and 128\n\n";
    int max = 128;
    int min = 1;
    int number = 64;
    for (int i=0; i<7; i++){
        cout << "Is the number you are thinking of greater than " << number << " (Yes or No)\n";
        string answer;
        cin >> answer;
        if (answer == no) {
            max = number;
            number = number - (number - (min - 1)) / 2.0;
        }
        else if (answer == yes) {
            min = number + 1;
            number = max - (max - (min - 1)) / 2.0;
        }

        else
            simple_error("Did not recognize answer");
    }
cout << "the number you are thinking of is " << min;
}
catch (runtime_error &e) {
    cerr << "runtime error: " << e.what() << '\n';
    return 1;
}
