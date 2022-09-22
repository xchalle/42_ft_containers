#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
	public:
		Node()
		{}
		Node(Node *left, Node *right, Node *inhe) : _left(left), _right(right), _inhe(inhe)
		{}
		Node(Node *left, Node *right, Node *inhe, T pair) : _left(left), _right(right), _inhe(inhe), _pair(pair)
		{}
		Node( Node &other) : _left(other._left), _right(other._right), _inhe(other._inhe), _pair(other._pair)
		{}
		Node &operator=(Node &other)
		{
			_left = other._left;
			_right = other._right;
			_inhe = other._inhe;
			_pair = other._pair;
			return (*this);
		}
		~Node()
		{}
	private:
		Node	*_left = std::nullptr;
		Node	*_right = std::nullptr;
		Node	*_inhe = std::nullptr;
		T	_pair;
}
#endif
