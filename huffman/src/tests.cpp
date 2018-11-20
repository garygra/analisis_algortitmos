#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;


int main (int argc, char *argv[])
{
	if (argc < 3)
	{
		cout << argv[0] << " needs two (big) numbers as arguments, but it only recevied " << argc - 1 << "." << endl;
		return 1;
		
	}

	// cout << "Result: " << res << " in: " << duration << " seconds." << endl;

  	return 0;
}