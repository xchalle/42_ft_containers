#include <vector>
#include "vector.hpp"
#include "rb_tree.hpp"
#include "pair.hpp"
#include <ostream>
#include <iostream>

int main() {
  RedBlackTree<ft::pair<int, int>> bst;
  bst.insert(ft::pair<int, int> (10, 1));
  bst.insert(65);
  bst.insert(60);
  bst.insert(75);
  bst.insert(57);

  bst.printTree();
  cout << endl
     << "After deleting" << endl;
  bst.deleteNode(40);
  bst.printTree();
}
