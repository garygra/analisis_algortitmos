#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>
#include <random>

// #include "node.hpp"
// #include "priority_queue.hpp"
#include "huffman.hpp"

using namespace std;


int main (int argc, char *argv[])
{
	// if (argc < 3)
	// {
	// 	cout << argv[0] << " needs two (big) numbers as arguments, but it only recevied " << argc - 1 << "." << endl;
	// 	return 1;
		
	// }

	huffman huffman;
	
	vector<char> v_chars{ 'a', 'b', 'c', 'd', 'e', 'f' }; 
	vector<int>    v_freqs{ 45, 13, 12, 16, 9, 5 }; 
	
	huffman.initialize(v_chars, v_freqs);

	huffman.get_solution();

	huffman.print_sol();

  	return 0;
}