#include "huffman.hpp"

using namespace std;


huffman::huffman()
{
  // num_elements = 0;
}
huffman::~huffman()
{
}

void huffman::get_solution()
{
	int n = queue.size() - 1; 
	for (int i = 0; i < n ; ++i)
	{
		// print_vector();
  	  	node_h *z = (node_h*) malloc(sizeof(node_h));
		node_h *x = queue.top();
		queue.pop();
		node_h *y = queue.top();
		queue.pop();
		z -> letter = '\t';
		z -> right = x;
		z -> left = y;
		z -> freq = x -> freq + y -> freq;
		queue.push(z);
	}
	// print_vector();
	// return queue.top();
}
  
void huffman::initialize(vector<char> vec_chars_in, vector<int> vec_frecs_in)
{
	assert(vec_chars_in.size() == vec_frecs_in.size());

	for (int i = 0; i < vec_chars_in.size(); ++i)
  	{
  	  	node_h *n = (node_h*) malloc(sizeof(node_h));
  	  	n -> letter = vec_chars_in[i];
  	  	n -> right = 0;
  	  	n -> left = 0;
  	  	n -> freq = vec_frecs_in[i];
  	  	queue.push(n);
  	}
}

void huffman::print_sol()
{
	cout << "Printing solution:" << endl;
	next_branch(0, queue.top());
}

void huffman::next_branch(int val, node_h* n)
{
	// n -> print_node_h(to_string(val));
	if (n -> left == NULL && n -> right == NULL)
	{
		cout << "Letter: " << n -> letter << "\tcode: " << val << endl;
	}
	else 
	{
		next_branch(val * 10 , n -> right); // derecha
		next_branch(val * 10 + 1, n -> left); // izquierda
	}
}

void huffman::print_vector()
{
	vector<node_h*> v = queue.get_vector();
	cout << "------- print_vector ------- " << endl;
 	int i = 0;
	for(auto n : v)
	{
		// cout << __LINE__ << endl;
		// cout << n -> letter << endl;
		// cout << n -> left << endl;
		// cout << n -> right << endl;
		// cout << n -> freq << endl;
		n -> print_node_h(to_string(i));
		i++;
	}

	cout << "----- end print_vector ----- " << endl;

}