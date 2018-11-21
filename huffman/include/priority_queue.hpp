#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_

// std
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iterator>

// own libraries
#include "node.hpp"

using namespace std;

class priority_queue
{
  private:
    vector<node_h*> nodes;
    // int num_elements;
    int lookup_node(node_h* node);
    // bool nodes_in_vecinity(node_h* p1, node_h* p2);

  public:

    priority_queue();
    virtual ~priority_queue();
    void push(node_h* node);
    node_h* top();
    void pop();
    bool empty();
    int size();
    void reset_queue();

    vector<node_h*> get_vector();
    void print_vector();
    bool node_in_queue(node_h* node);
    void remove_node_from_queue(node_h* node);
    bool point_in_queue();
};

#endif
