#include "node.hpp"

void node_h::print_node_h(std::string s)
{
	if (left != NULL && right != NULL)
	{
  		// std::cout << "---" << s <<" letter: " << letter << ": left = " << left << ", right = " << right << ", freq = " << freq << std::endl;
  		std::cout << "---" << s <<" letter: " << letter << ": left = " << left -> letter << ", right = " << right -> letter << ", freq = " << freq << std::endl;
	}
	else if (left != NULL)
	{
  		std::cout << "---" << s <<" letter: " << letter << ": left = " << left -> letter << ", right = " << right << ", freq = " << freq << std::endl;
	}
	else if (right != NULL)
	{
  		std::cout << "---" << s <<" letter: " << letter << ": left = " << left << ", right = " << right -> letter << ", freq = " << freq << std::endl;
	}
	else 
	{
		// std::cout << "else"<< std::endl;
  		std::cout << "---" << s <<" letter: " << letter << ": left = " << left << ", right = " << right << ", freq = " << freq << std::endl;
	}

}


// void node_h::set_letter(string letter_in)
// {
// 	letter = letter_in;
// }

// string node_h::get_letter()
// {
// 	return letter;
// }


// std::ostream& operator<<(std::ostream& os, const node_h& n)
// {
//     os << " left = " << n.left  -> letter << ", right = " << n.right -> letter << ", freq = " << n.freq; 

//     return os;
// }
