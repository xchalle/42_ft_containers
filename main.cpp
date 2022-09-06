#include <vector>
#include "vector.hpp"
#include "rb_tree.hpp"
#include "pair.hpp"
#include <ostream>
#include <iostream>

int main() {
	ft::RedBlackTree<ft::pair<int, int>, int> bst;
  bst.insert(ft::pair<int, int> (10, 110));
  bst.insert(ft::pair<int, int> (5, 15));
  bst.insert(ft::pair<int, int> (7, 17));
  bst.insert(ft::pair<int, int> (9, 19));
  bst.insert(ft::pair<int, int> (2, 12));

  bst.printTree();
  std::cout << std::endl
     << "After deleting" << std::endl;
  bst.printTree();
}
