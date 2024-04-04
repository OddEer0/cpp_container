CC=g++
CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17
LINK_GTEST = `pkg-config --libs gtest`
FLAG_GTEST = `pkg-config --cflags gtest`

test:
	$(CC) $(CPPFLAGS) $(FLAG_GTEST) __test__/*.cpp -o $@ $(LINK_GTEST)
	./testing

clean:
	rm -rf *.a *.o testing tree_main 

tree:
	$(CC) $(CPPFLAGS) main.cpp -o tree_main
	./tree_main