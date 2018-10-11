// #include "karatsuba.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>

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

	
	// first.insert (0, second);

	int carry = 0;
	string res("");
	string aux("");
	int i ;
	for (i = n-1; i > 3; i -= 4) // Change to a while: each string should have its own counter :s
	{	
		// cout << "n: " << n << "\ti: " << i << "\ti-3: " << i-3 << endl;
		// cout << "A: " << first << endl;
		// cout << "B: " << second << endl;
		aux = to_string(stoi(first.substr(i-3, 4)) + stoi(second.substr(i-3, 4)) + carry);
		// cout << "first:  " << first.substr(i-3, 4) << "\tsecond: " << second.substr(i-3, 4) << "\taux: " << aux << endl;
		if (aux.length() > 4)
		{
			// cout << "aux[4]: " << aux[0] << "\taux.substr(4): " << aux.substr(4) << endl;
			carry = aux[0] - '0';
			aux = aux.substr(1,4);
		} 
		else
		{
			carry = 0;
		}

		res.insert(0, aux);
		// cout << "aux: " << aux << "\tcarry: " << carry << "\tres: " << res << endl;
	}
		// cout << "n: " << n << "\ti: " << i << "\ti-3: " << i-3 << endl;
	if(i >= 0)
	{
		// cout << "after for: " << endl;
		int n_aux = (n%4 == 0) ? 4 : n%4;
		aux = to_string(stoi(first.substr(0, n_aux)) + stoi(second.substr(0, n_aux)) + carry );
		// cout << "first:  " << first.substr(0, n_aux) << "\tsecond: " << second.substr(0, n_aux) << "\taux: " << aux << endl;
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
	for (int i = n-1; i > 3; i -= 4) // Change to a while: each string should have its own counter :s
	{	
		// cout << "n: " << n << "\ti: " << i << "\ti-3: " << i-3 << endl;
		// cout << "A: " << first << endl;
		// cout << "B: " << second << endl;
		int_aux = stoi(first.substr(i-3, 4)) - stoi(second.substr(i-3, 4)) - carry;
		// cout << "first:  " << first.substr(i-3, 4) << "\tsecond: " << second.substr(i-3, 4) << "\tint_aux: " << int_aux << endl;
		if (int_aux < 0)
		{
			// cout << "aux[4]: " << aux[0] << "\taux.substr(4): " << aux.substr(4) << endl;
			
			carry = 1;
			aux = to_string(10000 + int_aux);
		} 
		else
		{
			carry = 0;
			aux = to_string(int_aux);
		}

		res.insert(0, aux);
		// cout << "aux: " << aux << "\tcarry: " << carry << "\tres: " << res << endl;
	}
		// cout << "n: " << n << "\ti: " << i << "\ti-3: " << i-3 << endl;
		// i +=4;
	if(i >= 0)
	{
		// cout << "after for: " << endl;
		int n_aux = (n%4 == 0) ? 4 : n%4;
		aux = to_string(stoi(first.substr(0, n_aux)) - stoi(second.substr(0, n_aux)) - carry );
		// cout << "first:  " << first.substr(0, n_aux) << "\tsecond: " << second.substr(0, n_aux) << "\taux: " << aux << endl;
		res.insert(0, aux);
	}
	return res;
}

string k_mul(string first, string second)
{
	prepend_zeros(&first, &second);
	int n = first.length();
	cout << "=================================================================" << endl;
	cout << "n: " << n << "\tfirst: " << first << "\tsecond: " << second << endl;
	if (n <= 1)
	{
		cout << "returning: " << stoi(first) << " * " << stoi(second) << endl;
		return to_string(stoi(first) * stoi(second));
	}

	int b = 10;
	string f_h = first.substr(0, n/2);
	string f_l = first.substr(n/2);

	string s_h = second.substr(0, n/2);
	string s_l = second.substr(n/2);

	cout << "f_h: " << f_h << "\tf_l: " << f_l << endl;
	cout << "s_h: " << s_h << "\ts_l: " << s_l << endl;
	string a = k_mul(f_h, s_h);
	string d = k_mul(f_l, s_l);

	// int n_1 = a.length();
	// int n_2 = d.length();
	// int n_aux = (n_1 > n_2) ? n_1 : n_2;
	// a.insert(0, n_aux - n_1, '0');
	// d.insert(0, n_aux - n_2, '0');


	// string e_aux1 = k_add(f_h, f_l);
	// string e_aux2 = k_add(s_h, s_l);
	// // prepend_zeros(&e_aux1, &e_aux2);
	// string e_aux3 = k_mul(e_aux1, e_aux2);
	// // prepend_zeros(&a, &d);
	// string e_aux4 = k_add(a, d);
	// cout << "k_add(f_h, f_l): " << e_aux1 << endl;
	// cout << "k_add(s_h, s_l): " << e_aux2 << endl;
	// cout << "e_aux3: " << e_aux3 << endl;
	// cout << "e_aux4: " << e_aux4 << endl;
	// string e_aux3 = k_mul(e_aux3, e_aux4);
	// string e = k_sub(e_aux3, e_aux4) ;

	string FhSl = k_mul(f_h, s_l); 
	string FlSh = k_mul(f_l, s_h); 
	cout << "FhSl: " << FhSl << endl;
	cout << "FlSh: " << FlSh << endl;
	string e = k_add(FhSl, FlSh);

	cout << "n: " << n << "\ta: " << a << "\td: " << d << "\te: " << e << endl;

	a.insert(a.length(), n, '0');
	int n_e = (n % 2 == 0) ? n >> 1 : n >> 1 + 1; 
	e.insert(e.length(), n_e , '0');

	cout << "xy: " << a << " + " << e << " + " << d << endl;
	return k_add(a, k_add(e, d));
	// string e = k_mul()
	// 5535

}

int main (int argc, char *argv[])
{
	if (argc < 3)
	{
		cout << argv[0] << " needs two (big) numbers as arguments, but it only recevied " << argc - 1 << "." << endl;
		return 1;
	}
	string first (argv[1]);
	string second (argv[2]);
	prepend_zeros(&first, &second);
	// int n_1 = first.length();
	// int n_2 = second.length();
	// int n = (n_1 > n_2) ? n_1 : n_2;
	// first.insert(0, n - n_1, '0');
	// second.insert(0, n - n_2, '0');
	cout << "First number:  "  << first << endl;
	cout << "Second number: " << second << endl;
	
	string res (k_mul(first, second));
	
	// cout << "The result is: " << res << endl;
	cout << "The result is: " << res << endl;




  	return 0;
}