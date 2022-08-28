#include <vector>
#include <memory>

template <typename T>
class TreeNode {
public:
	TreeNode() = default;
	TreeNode(T val) :value{ std::move(val) } {}
	void add_child(T value) {
		childs.emplace_back(std::make_unique<TreeNode>(value));
	}
	std::vector<std::unique_ptr<TreeNode>> childs;
	T value;



};



//TreeNode<int> tree{ 3 };
//tree.add_child(4);
//tree.add_child(5);
//tree.add_child(6);
//tree.add_child(7);
//
//auto child_node = tree.childs[3].get();
//child_node->add_child(8);
//child_node->add_child(9);
//child_node->add_child(10);