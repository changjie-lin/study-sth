#include <string>
using std::string;

class TreeNode {
public:
	TreeNode() : 
		value(string()), count(1), left(nullptr), right(nullptr) {}
	TreeNode(const string &s, int c) :
		value(s), count(c), left(nullptr), right(nullptr) {}

	TreeNode(const TreeNode&);
	TreeNode& operator=(const TreeNode&);
	~TreeNode();
private:
	std::string 	value;
	int 		count;
	TreeNode*	left;
	TreeNode*	right;

};

TreeNode::TreeNode(const TreeNode& n) :
	value(n.value), count(n.count), left(nullptr), right(nullptr) 
{
	// Recursively call Copy Constructor
	if (n.left)
		left = new TreeNode(*n.left);
	if (n.right)
		right = new TreeNode(*n.right);
}

/*
 * Recursively call destructor
 * When left or right is nullptr, delete will do nothing. Thus the resursion stops.
 *
 * */
TreeNode::~TreeNode()
{
	delete left;
	delete right;
}

TreeNode &TreeNode::operator=(const TreeNode &rhs)
{
	value = rhs.value;
	count = rhs.count;

	TreeNode* newNode = nullptr;
	// recursively call Copy Constructor
	if (rhs.left) newNode = new TreeNode(*rhs.left); 
	delete left; // recursively call Destructor
	left = newNode;

	newNode = nullptr;
	if (rhs.right) newNode = new TreeNode(*rhs.right);
	delete right;
	right = newNode;

	return *this;
}

/*
 * The valid state for the `root` pointer is that it always point to an existing
 * tree node. The `nullptr` is not a valid state. Thus we can dereference this pointer
 * without checking it is nullptr or not in Copy Constructor and Copy-assignment
 * operators. (Class Invariant)
 *
 * */
class BinStrTree { 
public:
	BinStrTree(const TreeNode &n = TreeNode()) :
		root(new TreeNode(n)), use(new std::size_t(1)) {}
	BinStrTree(const BinStrTree&);
	BinStrTree& operator=(const BinStrTree&);
	~BinStrTree();
private:
	TreeNode *root;
	std::size_t *use;
};

// Recursively call the Copy Constructor
BinStrTree::BinStrTree(const BinStrTree &bst) : 
	root(new TreeNode(*bst.root)), use(bst.use) { ++*use; }

BinStrTree &BinStrTree::operator=(const BinStrTree &rhs)
{
	++*rhs.use;
	if (--*use == 0) {
		delete root;
		delete use;
	}
	root = rhs.root;
	use = rhs.use;

	return *this;
}

// Recursively call the Destructor of `TreeNode`
BinStrTree::~BinStrTree()
{
	if (--*use == 0) {
		delete root;
		delete use;
	}
}

int main() 
{
	TreeNode node;

	BinStrTree bst;
}





