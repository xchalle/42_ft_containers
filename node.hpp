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
		Node	*_left;
		Node	*_right;
		Node	*_inhe;
		T	_pair;
}
