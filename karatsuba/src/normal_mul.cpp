#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>
#include "timer.hpp"

using namespace std;

int main (int argc, char *argv[])
{
	if (argc < 3)
	{
		cout << argv[0] << " needs two (big) numbers as arguments, but it only recevied " << argc - 1 << "." << endl;
		return 1;
	}
	sys_timer_t timer;

	string first (argv[1]);
	string second (argv[2]);
	// prepend_zeros(&first, &second);
	
	// cout << "First number:  "  << first << endl;
	// cout << "Second number: " << second << endl;
	
	timer.reset();
	string res (to_string(stoi(first) * stoi(second)));
	double duration = timer.measure();
	
	cout << "Result: " << res << " in: " << duration << " seconds." << endl;

  	return 0;
}