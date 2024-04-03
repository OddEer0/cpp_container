#include <iostream>
#include "redblacktree/redblacktree.h"
#include <map>

int main() {
    s21::RedBlackTree<int, int> tree;
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

	for (int i = 1; i <= 600; i++) {
		tree.insert(std::make_pair(i, i));
	}

	std::cout << tree.string() << std::endl;


    return 0;
}