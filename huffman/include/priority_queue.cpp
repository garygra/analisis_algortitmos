#include "priority_queue.h"

priority_queue::priority_queue()
{
  // num_elements = 0;
}
priority_queue::~priority_queue()
{
}

int priority_queue::lookup_node(node_h* node)
{
  int start = 0;
  int end = nodes.size();
  int search_i;
  while (start != end)
  {
    if(end - start == 1)
    {
      if (nodes[start] -> cost < node -> cost)
      {
        return end;
      }
      else
      {
        return start;
      }
    }

    search_i = ( start + end ) / 2;
    if (node -> cost == nodes[search_i] -> cost)
    {
      return search_i;
    }
    else if (node -> cost < nodes[search_i] -> cost)
    {
      end = search_i;
    }
    else
    {
      start = search_i;
    }


  }
  return start;
}

// bool priority_queue::nodes_in_vecinity(node_h* n1, node_h* n2)
// {
//   double dx = fabs(n1 -> point.x - n2 -> point.x);
//   double dy = fabs(n1 -> point.y - n2 -> point.y);
//   double dc = fabs(n1 -> cost    - n2 -> cost);

//   return dx <= TOLERANCE_RAD && dy <= TOLERANCE_RAD && dc <= TOLERANCE_COST;
// }

// bool priority_queue::point_in_queue()
// {
//   std::cout << __PRETTY_FUNCTION__ << '\n';
//   for (size_t i = 0; i < nodes.size(); i++)
//   {
//     for (size_t j = 0; j < nodes.size(); j++) {
//       // if(i != j && nodes[i] -> point.x == nodes[j] -> point.x && nodes[i] -> point.y == nodes[j] -> point.y)
//       if(i != j && nodes_in_vecinity(nodes[i], nodes[j]))
//       {
//         std::cout << "Found equal nodes:" << '\n';
//         std::cout << "---n: cost = " << nodes[i] -> cost << " - (" << nodes[i] -> point.x << ", " << nodes[i] -> point.y << "). Parent " << nodes[i] -> parent << std::endl;
//         std::cout << "---o: cost = " << nodes[j] -> cost << " - (" << nodes[j] -> point.x << ", " << nodes[j] -> point.y << "). Parent " << nodes[j] -> parent << std::endl;
//       }
//     }
//   }
// }

void priority_queue::push(node_h* node)
{
  double cost = node -> cost;
  int i = lookup_node(node);

  nodes.insert(nodes.begin()+i, node);

}

bool priority_queue::empty()
{
  return size() == 0;
}

int priority_queue::size()
{
  return nodes.size();
}

node_h* priority_queue::top()
{
  return nodes[0];
}

void priority_queue::pop()
{
  nodes.erase(nodes.begin());
}

bool priority_queue::node_in_queue(node_h* node)
{
  int i = lookup_node(node);
  if (0 < i && i == nodes.size())
  {
    return false;
  }
  else
  {
    return nodes_in_vecinity(node, nodes[i]);
  }
}

void priority_queue::remove_node_from_queue(node_h* node)
{
  int i = lookup_node(node);
  if (node -> cost == nodes[i] -> cost & ARE_NODES_PTR_EQUAL(node, nodes[i]))
  {
    nodes.erase(nodes.begin()+i);
  }
}

std::vector<node_h*> priority_queue::get_vector()
{
  return nodes;
}

void priority_queue::print_vector()
{
  int i = 0;
  for (auto n : nodes)
  {
    std::cout << i <<  ": cost = " << n -> cost << " - (" << n -> point.x << ", " << n -> point.y << "). Parent " << n -> parent << std::endl;
    i++;
  }
}

void priority_queue::reset_queue()
{
  nodes.clear();
}