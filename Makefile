CC=g++
CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17
LINK_GTEST = `pkg-config --libs gtest`
FLAG_GTEST = `pkg-config --cflags gtest`

test:
	$(CC) $(CPPFLAGS) $(FLAG_GTEST) *.cpp __test__/*.cpp -o $@ $(LINK_GTEST)
	./$@

clean:
	rm -rf *.a *.o test tree_main

tree:
	$(CC) $(CPPFLAGS) main.cpp -o tree_main
	./tree_main