#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>
#include <random>
#include <math.h> 
#include <ctime>
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
	
	// vector<char> v_chars{ 'a', 'b', 'c', 'd', 'e', 'f' }; 
	// vector<int>    v_freqs{ 45000, 13000, 12000, 16000, 9000, 5000 }; 
	vector<char> v_chars; 
	vector<int>  v_freqs; 
	char letter = 'a';
	int freq = 0;
	srand(time(NULL));
	for (int i = 0; i < 26; ++i)
	{
		v_chars.push_back(letter);
		freq = (rand() % 100) * 1000;
		v_freqs.push_back(freq);
		cout << letter << ":" << freq << ". ";
		letter++;
	}
	cout << endl;

	huffman.initialize(v_chars, v_freqs);

	huffman.get_solution();

	huffman.print_sol();

	int bits = ceil(log2(v_chars.size()));
	int sum = 0;
	for (auto e : v_freqs)
	{
		sum += e;
	}

	cout << "With fixed encoding, the file will have " << bits * sum << " bits." << endl;


  	return 0;
}