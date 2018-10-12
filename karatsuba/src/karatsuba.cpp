// #include "karatsuba.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>
#include "timer.hpp"

using namespace std;


void prepend_zeros(string *first, string *second)
{
	int n_1 = first -> length();
	int n_2 = second -> length();
	int n = (n_1 > n_2) ? n_1 : n_2;
	first -> insert(0, n - n_1, '0');
	second -> insert(0, n - n_2, '0');
}

string k_add(string first, string second)
{
	prepend_zeros(&first, &second);
	int n = first.length();
	int carry = 0;
	string res("");
	string aux("");
	string dummy("XXXX");
	int i ;
	for (i = n-1; i > 3; i -= 4) 
	{	

		aux = to_string(stoi(first.substr(i-3, 4)) + stoi(second.substr(i-3, 4)) + carry);
		prepend_zeros(&aux, &dummy);
		if (aux.length() > 4)
		{
			carry = aux[0] - '0';
			aux = aux.substr(1,4);
		} 
		else
		{
			carry = 0;
		}

		res.insert(0, aux);
	}
	if(i >= 0)
	{
		int n_aux = (n%4 == 0) ? 4 : n%4;
		aux = to_string(stoi(first.substr(0, n_aux)) + stoi(second.substr(0, n_aux)) + carry );
		res.insert(0, aux);
	}
	return res;
}

string k_sub(string first, string second)
{
	prepend_zeros(&first, &second);
	int n = first.length();

	int carry = 0;
	int int_aux = 0;
	string res("");
	string aux("");
	int i ;
	for (int i = n-1; i > 3; i -= 4)
	{	
		int_aux = stoi(first.substr(i-3, 4)) - stoi(second.substr(i-3, 4)) - carry;
		if (int_aux < 0)
		{
			carry = 1;
			aux = to_string(10000 + int_aux);
		} 
		else
		{
			carry = 0;
			aux = to_string(int_aux);
		}
		res.insert(0, aux);
	}

	if(i >= 0)
	{
		int n_aux = (n%4 == 0) ? 4 : n%4;
		aux = to_string(stoi(first.substr(0, n_aux)) - stoi(second.substr(0, n_aux)) - carry );
		res.insert(0, aux);
	}
	return res;
}

string k_mul(string first, string second)
{
	prepend_zeros(&first, &second);
	int n = first.length();
	int n_exp = (n % 2 == 1) ? n + 1 : n ; 

	if (n <= 4)
	{
		return to_string(stoi(first) * stoi(second));
	}

	string f_h = first.substr(0, n/2);
	string f_l = first.substr(n/2);

	string s_h = second.substr(0, n/2);
	string s_l = second.substr(n/2);


	string a = k_mul(f_h, s_h);
	string d = k_mul(f_l, s_l);

	string FhSl = k_mul(f_h, s_l); 
	string FlSh = k_mul(f_l, s_h); 

	string e = k_add(FhSl, FlSh);

	a.insert(a.length(), n_exp, '0');
	e.insert(e.length(), n_exp>>1 , '0');

	return k_add(a, k_add(e, d));
}

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
	prepend_zeros(&first, &second);
	
	// cout << "First number:  "  << first << endl;
	// cout << "Second number: " << second << endl;
	
	timer.reset();
	string res (k_mul(first, second));
	double duration = timer.measure();
	
	cout << "Result: " << res << " in: " << duration << " seconds." << endl;

  	return 0;
}