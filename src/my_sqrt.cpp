#include "eecs230.h"

static const double epsilon {1e-8};

void error(string s){
    throw runtime_error(s);
}


double my_sqrt(double input, double epsilon) {
    double x = input ;
    while (x >= epsilon) {
        if (input / x == x)
            return x;
        else
            x = (x+input/x)/2;
    }
}

int main()
try {
    cout<<"enter a number";
    double number;
    cin >> number;
    if (number<0) simple_error("number was negative");
    cout<< my_sqrt(number, epsilon);
}

catch (runtime_error &e) {
   cerr << "runtime error: " << e.what() << '\n';
   return 1;
}
