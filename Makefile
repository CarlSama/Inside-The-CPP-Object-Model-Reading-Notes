all:cast

cast:cast.cpp
	g++ -std=c++11 $^ -o $@
