#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "utils.hpp"
#include "pair.hpp"
#include "rb_tree.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "rb_iterator.hpp"

namespace ft{
template<
class Key,
class T,
class Compare = std::less<Key>,
class Allocator = std::allocator<ft::pair<const Key, T> >
> class map
{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::bidirectional_iterator<node< value_type>, value_type> iterator;
		typedef ft::bidirectional_iterator<node< value_type>, const value_type> const_iterator;
		//class iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	protected:
		typedef node<value_type> *nodeptr;

	public:
		//VALUE_COMPARE TODO
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			protected :
			value_compare( key_compare c) : _comp(c)
			{
			}
			key_compare _comp;
			public:
			result_type operator() ( const value_type& lhs, const value_type& rhs) const
			{
				return _comp(lhs.first, rhs.first);
			}
		};
		key_compare				_comp;
		allocator_type				_alloc;
		rb_tree<value_type, value_compare>	_rbt;

		//CONSTRUCTOR TODO
		map() : _comp(key_compare()), _alloc(Allocator()), _rbt(value_compare(_comp))
		{
		}
		explicit map( const Compare& comp,
				const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc), _rbt(value_compare(_comp))
		{
		}
		template < class InputIt>
			map( InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator& alloc = Allocator()) : _comp(comp), _alloc(alloc), _rbt(value_compare(_comp))
			{
				insert(first, last);
			//	while (first != last)
			//	{
			//		_rbt.insert(*first);
			//		first++;
			//	}
			}
		map (const map &rhs) : _rbt(value_compare(key_compare()))
	{
		insert(rhs.begin(), rhs.end());
	}
		//DESTRUCTOR
		~map()
		{ 
			_rbt.destroy();
			_rbt.destroy_end();

		}


		//OPERTOR=
		map& operator=(const map& other)
		{
		//	if (*this == other)
		//		return (*this);
			clear();
			insert(other.begin(), other.end());
			//TODO
			return (*this);
		}
		//GET_ALLOCATOR
		allocator_type get_allocator() const {return (_alloc);}
		mapped_type& at( const key_type& key)
		{
			return (_rbt.search(ft::make_pair(key, mapped_type()))->data.second);
		}
		const mapped_type& at( const key_type& key) const
		{
			return (_rbt.search(ft::make_pair(key, mapped_type()))->data.second);
		}
		mapped_type& operator[]( const key_type& key)
		{
			insert(ft::make_pair(key, mapped_type()));
			return (_rbt.search(ft::make_pair(key, mapped_type()))->data.second);
			
		//	return (_rbt.search(key)->data.second);
		}
		//BEGIN//cosnt_fct TODO
		iterator begin()
		{
			return (iterator(_rbt.min(), _rbt.get_end(), _rbt.get_root()));
		}
		const_iterator begin() const 
		{
			return (const_iterator(_rbt.min(), _rbt.get_end(), _rbt.get_root()));
		}
		//END//cosnt_fct TODO
		iterator end()
		{
			return (iterator(_rbt.get_end(), _rbt.get_end(), _rbt.get_root()));
		}
		//iterator root()
		//{
		//	return (_root);
		//}
		const_iterator end() const
		{
			return (const_iterator(_rbt.get_end(), _rbt.get_end(), _rbt.get_root()));
		}
		//RBEGIN//cosnt_fct TODO
		reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}
		//REND //cosnt_fct TODO
		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		}
		//EMPTY
		bool empty() const
		{
			if (begin() == end())
				return true;
			return false;
		}
		//SIZE
		size_type size() const
		{
			return (ft::distance(begin(), end()));
		}
		//MAX_SIZE
		size_type max_size() const
		{
			return (_rbt.max_size());
		}
		//CLEAR
		void clear()
		{
			_rbt.destroy();
		}
		//INSERT
		ft::pair<iterator, bool> insert(const value_type& value)
		{
			bool tmp = _rbt.insert(value);
			return (ft::make_pair<iterator, bool>(iterator(_rbt.search(value), _rbt.get_end(), _rbt.get_root()), tmp));
		}
		iterator insert(iterator hint, const value_type& value)
		{
			(void)hint;
			_rbt.insert(value);
			return(iterator(_rbt.search(value), _rbt.get_end(), _rbt.get_root()));
		}
		template<class InputIt>
		void insert(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = ft::nullptr_a)
		{
			while(first != last)
				_rbt.insert(*first++);
		}
		//ERASE
		iterator erase(iterator pos)
		{
			_rbt.delete_node(*pos);
			return end();
		}
		iterator erase(iterator first, iterator last)
		{
			//last--;
			while (first != last)
			{
				first = find(first->first);
				//iterator tmp = last--;
				erase(first++);
				//_rbt.delete_node(*(first++));
			}
			//_rbt.delete_node(*(last));
			return end();
		}
		size_type erase (const Key& key)
		{
			if (_rbt.delete_node(ft::make_pair(key, mapped_type())))
				return 1;
			return 0;
		}
		//SWAP
		void swap(map &other)
		{
			_rbt.swap(other._rbt);
		}
		//KEY_COMP
		/*key_compare key_comp() const
		{
			return _comp;
		}
		//VALUE_COMP
		value_compare value_comp() const
		{
			return value_compare(_comp);
		}*/
		//COUNT
		size_type count( const Key& key) const
		{
			if (find(key) != end())
				return 1;
			return 0;
		}
		//FIND
		iterator find( const Key& key)
		{
			return(iterator(_rbt.search(ft::make_pair(key, mapped_type())), _rbt.get_end(), _rbt.get_root()));
		}
		const_iterator find( const Key& key) const
		{
			return(const_iterator(_rbt.search(ft::make_pair(key, mapped_type())), _rbt.get_end(), _rbt.get_root()));
		}
		//LOWER_BOUND
		const_iterator lower_bound( const Key& key) const
		{
			return (const_iterator(_rbt.lower_bound(ft::make_pair(key, mapped_type())), _rbt.get_end(), _rbt.get_root()));
		}
		iterator lower_bound( const Key& key)
		{
			return (iterator(_rbt.lower_bound(ft::make_pair(key, mapped_type())), _rbt.get_end(), _rbt.get_root()));
		}
		const_iterator upper_bound( const Key& key) const
		{
			return (const_iterator(_rbt.upper_bound(ft::make_pair(key, mapped_type())), _rbt.get_end(), _rbt.get_root()));
		}
		iterator upper_bound( const Key& key)
		{
			return (iterator(_rbt.upper_bound(ft::make_pair(key, mapped_type())), _rbt.get_end(), _rbt.get_root()));
		}
		//EQUAL_RANGE
		ft::pair<iterator, iterator> equal_range(const Key& key)
		{
			return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const
		{
			return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}
		//KEY_COMP
		key_compare key_comp() const
		{
			return (_comp);
		}
		//VALUE_COMP
		value_compare value_comp() const
		{
			return (_comp);
		}
};

	template< class Key , class Compare, class Alloc >
	bool operator==( const ft::map<Key, Compare, Alloc>& lhs, const ft::map<Key, Compare, Alloc>& rhs)
	{
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && ft::equal(rhs.begin(), rhs.end(), lhs.begin()))
			return true;
		return false;

	}
	template< class Key , class Compare, class Alloc >
	bool operator!=( const ft::map<Key, Compare, Alloc>& lhs, const ft::map<Key, Compare, Alloc>& rhs)
	{
		if(lhs == rhs)
			return false;
		return true;
	}
	template< class Key , class Compare, class Alloc >
	bool operator<( const ft::map<Key, Compare, Alloc>& lhs, const ft::map<Key, Compare, Alloc>& rhs)
	{
		if(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
			return true;
		return false;
	}
	template< class Key , class Compare, class Alloc >
	bool operator<=( const ft::map<Key, Compare, Alloc>& lhs, const ft::map<Key, Compare, Alloc>& rhs)
	{
		if(lhs < rhs || lhs == rhs)
			return true;
		return false;
	}
	template< class Key , class Compare, class Alloc >
	bool operator>( const ft::map<Key, Compare, Alloc>& lhs, const ft::map<Key, Compare, Alloc>& rhs)
	{
		if (lhs <= rhs)
			return false;
		return true;
	}
	template< class Key , class Compare, class Alloc >
	bool operator>=( const ft::map<Key, Compare, Alloc>& lhs, const ft::map<Key, Compare, Alloc>& rhs)
	{
		if (lhs < rhs)
			return false;
		return true;
	}
	template<class Key, class Compare, class Alloc>
	void swap(ft::map<Key, Compare, Alloc>& lhs, ft::map<Key, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}

/*namespace ft{
template<
class Key,
class T,
class Compare = std::less<Key>,
class Allocator = std::allocator<ft::pair<const Key, T> >
> class map
{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef typename ft::pair<const Key, T> value_type;
		typedef Node<value_type> *nodeptr;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
	//	typedef ft::bidirectional_iterator<Node<ft::pair<const Key, T> >, key_compare> iterator;
		//	typedef ft::const_bidirectional_iterator<Node<const T>, key_compare> const_iterator;
		class iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		//	typedef ft::const_reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::allocator<Node<ft::pair<const Key, T> > > node_allocator;

		nodeptr _root;
		nodeptr _TNULL;
		key_compare _comp;
		allocator_type _alloc;
		node_allocator _node_alloc;
		

		//VALUE_COMPARE TODO
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			protected :
			value_compare( Compare c) : _comp(c)
			{
			}
			Compare _comp;
			result_type operator() ( const value_type& lhs, const value_type& rhs) const
			{
				return _comp(lhs.first, rhs.first);
			}
		};

		class iterator : public ft::iterator<bidirectional_iterator_tag, pointer>
		{
			public:
			typedef typename ft::iterator<bidirectional_iterator_tag, pointer>::iterator_category iterator_category;
			typedef typename ft::iterator<bidirectional_iterator_tag, pointer>::value_type value_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, pointer>::difference_type difference_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, pointer>::reference reference;
			//typedef typename ft::iterator<bidirectional_iterator_tag, pointer>::pointer pointer;
			iterator() : _node(ft::nullptr_a)
			{}
			       iterator(nodeptr ptr) : _node(ptr)
			{}
			iterator(const iterator &rhs) : _node(rhs._node)
			{}
			iterator& operator=(const iterator &rhs)
			{
				_node = rhs._node;
				return (*this);
			}
			~iterator()
			{};
			pointer get_ptr() const
			{return this->_node.val;}
			reference operator*() const
			{
				return *(_node->data);
			}
			pointer operator->() const
			{
				return (&(_node->data));
			}
			iterator& operator++()
			{
				this->_node = successor(_node);
				return (*this);
			}
			iterator& operator++(int)
			{
				iterator tmp(*this);
				this->_node = successor(_node);
				return (tmp);
			}
			iterator& operator--()
			{
				this->_node = predecessor(_node);
				return (*this);
			}
			iterator& operator--(int)
			{
				iterator tmp(*this);
				this->_node = predecessor(_node);
				return (tmp);
			}
			private:
			nodeptr _node;
		};



		//CONSTRUCTOR TODO
		map() : _comp(key_compare()), _alloc(Allocator())
		{
			RedBlackTree();
		}
		explicit map( const Compare& comp,
				const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc)
		{
			RedBlackTree();
		}
		//DESTRUCTOR
		~map()
		{}


		//OPERTOR=
		map& operator=(const map& other)
		{
			if (*this == other)
				return (*this);
			clear();
			isert(begin(), other.begin(), other.end());
			//TODO
			return (*this);
		}
		//GET_ALLOCATOR
		allocator_type get_allocator() const {return (_alloc);}
		//AT
		mapped_type& at( const Key& key ) 
		{
			nodeptr node = searchTree(key);
			if (node == _TNULL)
				throw std::out_of_range("exception at operation is out of range");
			return (node->data.second);
		}
		const mapped_type& at( const Key& key ) const 
		{
			nodeptr node = searchTree(key);
			if (node == _TNULL)
				throw std::out_of_range("exception at operation is out of range");
			return (node->data.second);
		}
		//OPERATOR []
		mapped_type& operator[] (const Key& key)
		{
			nodeptr node = searchTree(key);
			return (node->data.second);
		}
		//BEGIN//cosnt_fct TODO
		iterator begin()
		{
			return (minimum(_root));
		}
		
		const_iterator begin() const 
		{
			return (minimum(_root));
		}
		
		//END//cosnt_fct TODO
		iterator end()
		{
			return (maximum(_root));
		}
		iterator root()
		{
			return (_root);
		}
		
		 * const_iterator end() const
		{
			return (maximum(_root));
		}
		*/
		//RBEGIN//cosnt_fct TODO
		/*reverse_iterator rbegin()
		{
			return (maximum(_root));
		}
		const_reverse_iterator rbegin() const
		{
			return (maximum(_root));
		}
		//REND //cosnt_fct TODO
		reverse_iterator rend()
		{
			return (minimum(_root));
		}
		const_reverse_iterator rend() const
		{
			return (minimum(_root));
		}
		//EMPTY
		bool empty() const
		{
			if (begin() == end())
				return true;
			return false;
		}
		//SIZE
		size_type size() const
		{
			return (ft::distance(begin(), end()));
		}
		//MAX_SIZE
		size_type max_size() const
		{
			return (_node_alloc.max_size());
		}
		//CLEAR
		void clear()
		{
			while (_root != nullptr_a)
			{
				deleteRoot();
			}
		}
		//KEY_COMP
		key_compare key_comp() const
		{
			return _comp;
		}
		//VALUE_COMP
		value_compare value_comp() const
		{
			return value_compare(_comp);
		}
		//COUNT
		size_type count( const Key& key) const
		{
			if (find(key) != end())
				return 1;
			return 0;
		}
		//FIND
		iterator find( const Key& key)
		{
			return(iterator(searchTree(key)));
		}



void initializeNULLNode(nodeptr node, nodeptr parent) {
node->data = 0;
node->parent = parent;
node->left = ft::nullptr_a;
node->right = ft::nullptr_a;
node->color = 0;
}

// Preorder
void preOrderHelper(nodeptr node) {
if (node != _TNULL) {
std::cout << node->data << " ";
preOrderHelper(node->left);
preOrderHelper(node->right);
}
}

// Inorder
void inOrderHelper(nodeptr node) {
if (node != _TNULL) {
inOrderHelper(node->left);
std::cout << node->data << " ";
inOrderHelper(node->right);
}
}

// Post order
void postOrderHelper(nodeptr node) {
if (node != _TNULL) {
postOrderHelper(node->left);
postOrderHelper(node->right);
std::cout << node->data << " ";
}
}

nodeptr searchTreeHelper(nodeptr node, T key) {
if (node == _TNULL || key == node->data.first) {
return node;
}

if (_comp(key, node->data.first)) {
return searchTreeHelper(node->left, key);
}
return searchTreeHelper(node->right, key);
}

// For balancing the tree after deletion
void deleteFix(nodeptr x) {
nodeptr s;
while (x != _root && x->color == 0) {
if (x == x->parent->left) {
s = x->parent->right;
if (s->color == 1) {
  s->color = 0;
  x->parent->color = 1;
  leftRotate(x->parent);
  s = x->parent->right;
}

if (s->left->color == 0 && s->right->color == 0) {
  s->color = 1;
  x = x->parent;
} else {
  if (s->right->color == 0) {
    s->left->color = 0;
    s->color = 1;
    rightRotate(s);
    s = x->parent->right;
  }

  s->color = x->parent->color;
  x->parent->color = 0;
  s->right->color = 0;
  leftRotate(x->parent);
  x = _root;
}
} else {
s = x->parent->left;
if (s->color == 1) {
  s->color = 0;
  x->parent->color = 1;
  rightRotate(x->parent);
  s = x->parent->left;
}

if (s->right->color == 0 && s->right->color == 0) {
  s->color = 1;
  x = x->parent;
} else {
  if (s->left->color == 0) {
    s->right->color = 0;
    s->color = 1;
    leftRotate(s);
    s = x->parent->left;
  }

  s->color = x->parent->color;
  x->parent->color = 0;
  s->left->color = 0;
  rightRotate(x->parent);
  x = _root;
}
}
}
x->color = 0;
}

void rbTransplant(nodeptr u, nodeptr v) {
if (u->parent == ft::nullptr_a) {
_root = v;
} else if (u == u->parent->left) {
u->parent->left = v;
} else {
u->parent->right = v;
}
v->parent = u->parent;
}

void deleteNodeHelper(nodeptr node, T key) {
nodeptr z = _TNULL;
nodeptr x, y;
while (node != _TNULL) {
if (node->data == key) {
z = node;
}

if (node->data <= key) {
node = node->right;
} else {
node = node->left;
}
}

if (z == _TNULL) {
std::cout << "Key not found in the tree" << std::endl;
return;
}

y = z;
int y_original_color = y->color;
if (z->left == _TNULL) {
x = z->right;
rbTransplant(z, z->right);
} else if (z->right == _TNULL) {
x = z->left;
rbTransplant(z, z->left);
} else {
y = minimum(z->right);
y_original_color = y->color;
x = y->right;
if (y->parent == z) {
x->parent = y;
} else {
rbTransplant(y, y->right);
y->right = z->right;
y->right->parent = y;
}

rbTransplant(z, y);
y->left = z->left;
y->left->parent = y;
y->color = z->color;
}
_node_alloc.destroy(z);
_node_alloc.deallocate(z, 1);
if (y_original_color == 0) {
deleteFix(x);
}
}

// For balancing the tree after insertion
void insertFix(nodeptr k) {
nodeptr u;
while (k->parent->color == 1) {
if (k->parent == k->parent->parent->right) {
u = k->parent->parent->left;
if (u->color == 1) {
  u->color = 0;
  k->parent->color = 0;
  k->parent->parent->color = 1;
  k = k->parent->parent;
} else {
  if (k == k->parent->left) {
    k = k->parent;
    rightRotate(k);
  }
  k->parent->color = 0;
  k->parent->parent->color = 1;
  leftRotate(k->parent->parent);
}
} else {
u = k->parent->parent->right;

if (u->color == 1) {
  u->color = 0;
  k->parent->color = 0;
  k->parent->parent->color = 1;
  k = k->parent->parent;
} else {
  if (k == k->parent->right) {
    k = k->parent;
    leftRotate(k);
  }
  k->parent->color = 0;
  k->parent->parent->color = 1;
  rightRotate(k->parent->parent);
}
}
if (k == _root) {
break;
}
}
_root->color = 0;
}

void test()
{
		ft::pair<int, int> t;
		ft::map<int, int>::iterator tmp = root();
	while (*tmp != ft::nullptr_a)
	{
		t = *tmp;
		std::cout << t.second << std::endl;
		tmp++;
	}
}
void printHelper(nodeptr __root, std::string indent, bool last) {
if (_root != ft::nullptr_a)
{
	std::cout << indent;
	if (last)
	{
		std::cout << "R----";
		indent += "   ";
	}
	else
	{
		std::cout << "L----";
		indent += "|  ";
	}

	std::string sColor = __root->color ? "RED" : "BLACK";
	std::cout << __root->data.first << "(" << sColor << ")" << std::endl;
	printHelper(_root->left, indent, false);
	printHelper(_root->right, indent, true);
}
}

nodeptr RedBlackTree() {
_TNULL = _node_alloc.allocate(1);
_TNULL->color = 0;
_TNULL->left = ft::nullptr_a;
_TNULL->right = ft::nullptr_a;
_root = _TNULL;
return _root;
}

void preorder() {
preOrderHelper(this->_root);
}

void inorder() {
inOrderHelper(this->_root);
}

void postorder() {
postOrderHelper(this->_root);
}

nodeptr searchTree(key_type key) {
return searchTreeHelper(this->_root, key);
}

nodeptr minimum(nodeptr node) {
while (node->left != _TNULL) {
node = node->left;
}
return node;
}

nodeptr maximum(nodeptr node) {
while (node->right != _TNULL) {
node = node->right;
}
return node;
}

nodeptr successor(nodeptr x) {
if (x->right != _TNULL) {
return minimum(x->right);
}

nodeptr y = x->parent;
while (y != _TNULL && x == y->right) {
x = y;
y = y->parent;
}
return y;
}

nodeptr predecessor(nodeptr x) {
if (x->left != _TNULL) {
return maximum(x->left);
}

nodeptr y = x->parent;
while (y != _TNULL && x == y->left) {
x = y;
y = y->parent;
}

return y;
}

void leftRotate(nodeptr x) {
nodeptr y = x->right;
x->right = y->left;
if (y->left != _TNULL) {
y->left->parent = x;
}
y->parent = x->parent;
if (x->parent == ft::nullptr_a) {
this->_root = y;
} else if (x == x->parent->left) {
x->parent->left = y;
} else {
x->parent->right = y;
}
y->left = x;
x->parent = y;
}

void rightRotate(nodeptr x) {
nodeptr y = x->left;
x->left = y->right;
if (y->right != _TNULL) {
y->right->parent = x;
}
y->parent = x->parent;
if (x->parent == ft::nullptr_a) {
this->_root = y;
} else if (x == x->parent->right) {
x->parent->right = y;
} else {
x->parent->left = y;
}
y->right = x;
x->parent = y;
}

// Inserting a node
//template<class T1, class T2>
void insert(ft::pair<const Key, T> duo) {
nodeptr node = _node_alloc.allocate(1);
node->parent = ft::nullptr_a;
_alloc.construct(&node->data, duo);
node->left = _TNULL;
node->right = _TNULL;
node->color = 1;

nodeptr y = ft::nullptr_a;
nodeptr x = this->_root;

while (x != _TNULL) {
y = x;
if (_comp(node->data.first, x->data.first)) {
x = x->left;
} else {
x = x->right;
}
}

node->parent = y;
if (y == ft::nullptr_a) {
_root = node;
} else if (_comp(node->data.first, y->data.first)) {
y->left = node;
} else {
y->right = node;
}

if (node->parent == ft::nullptr_a) {
node->color = 0;
return;
}

if (node->parent->parent == ft::nullptr_a) {
return;
}

insertFix(node);
}

nodeptr getRoot() {
return this->_root;
}
void deleteNode(T data) {
deleteNodeHelper(this->_root, data);
}

void deleteRoot() {
deleteNodeHelper(this->_root, _root->data.first);
}
void printTree() {
if (_root) {
printHelper(this->_root, "", true);
}
}
};*/
}

#endif 
