#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
// ros messages
// #include <geometry_msgs/Point.h>
// #include <geometry_msgs/Pose.h>
// #include <geometry_msgs/Pose2D.h>

// ros
// #include <tf/tf.h>
// #include <tf/transform_datatypes.h>
// #include <LinearMath/btMatrix3x3.h>

// #define ARE_NODES_PTR_EQUAL(A, B) (A -> point.x == B -> point.x & A -> point.y == B -> point.y)

using namespace std;

class node_h
{
  private:
  
  public:
    char letter;
  
    node_h* left;
    node_h* right;
    int freq;
    void print_node_h(std::string s);

    // void set_letter(string letter_in);

    // string get_letter();

    friend std::ostream &operator<<(std::ostream&, const node_h& n);

    //Overload the < operator.
bool operator< (const node_h& other)
{
  return this -> freq > other.freq;
}
//Overload the > operator.
bool operator> (const node_h& other)
{
  return this -> freq < other.freq;
}

// bool operator==(const node_h& other)
// {
//   return this -> freq == other.freq && this -> left == other.left && this -> right == other.right;
// }

bool operator!=(const node_h& other)
{
  return !(this -> freq == other.freq && this -> left == other.left && this -> right == other.right);
  // return !(this == *other);
}


};


// struct node_h_ptrs_cmp
// {
//     bool operator()(const node_h* n1, const node_h* n2) const
//     {
//         return n1 -> cost < n2 -> cost;
//     }
// };


#endif
