#include <iostream>
using namespace std;
#include "convert_knots.hpp"

int main(){
    int knots = 0;
	cout << "Enter integer speed in knots";
	cin >> knots;
	cout << "This is your speed in miles per minute:" << knots_to_miles_per_minute(knots) << endl;
	return 0;
}
