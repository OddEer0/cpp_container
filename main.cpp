#include <iostream>
#include "redblacktree/redblacktree.h"

int main() {
    // s21::RedBlackTree<int, int> tree;
    // tree.insert(std::make_pair( 1000, 1000));
	// tree.insert(std::make_pair( 1050, 1050));
	// tree.insert(std::make_pair( 950, 950));
	// tree.insert(std::make_pair( 700, 700));
	// tree.insert(std::make_pair( 960, 960));
	// tree.insert(std::make_pair( 1030, 1030));
	// tree.insert(std::make_pair( 1100, 1100));
	// tree.insert(std::make_pair( 1150, 1150));
	// tree.insert(std::make_pair( 1200, 1200));
	// tree.insert(std::make_pair( 1250, 1250));
    // tree.insert(std::make_pair( 1220, 1220));
	// tree.insert(std::make_pair( 600, 600));
	// tree.insert(std::make_pair( 650, 650));

    // tree.insert_or_assign(std::make_pair( 650, 6650));

    // std::cout << tree.empty() << std::endl;
    // std::cout << tree.size() << std::endl;
    // std::cout << tree.max_size() << std::endl;

    // std::cout << tree.string() << std::endl;

	s21::RedBlackTree<int, int> tree2 = {
		{100, 100},
		{150, 150},
		{50, 50},
		{200, 200},
		{250, 250},
	};

	std::cout << tree2.string() << std::endl;

	std::cout << tree2[50] << std::endl;

	std::cout << tree2.at(200) << std::endl;

    return 0;
}