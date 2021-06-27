# include <iostream>
# include "static-stack.h"

int main(int argc,char* argv[]) {
	static_stack<int> ss;

	ss.push(42);
	ss.push(15);
	ss.pop();
	for (int i = 0; i < 100; i+=5)
		ss.push(i);

	static_stack<int>::const_iterator iter = ss.begin();
	while(iter != ss.end()) {
		std::cout << *iter << " ";
		++iter;
	}
	std::cout << std::endl;

	for (int i : ss)
		std::cout << i << " ";
	std::cout << std::endl;
}
