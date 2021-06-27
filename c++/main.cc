#include "static-stack.h"
#include "dynamic-stack.h"
# include <iostream>

template <typename T>
void anyadir_elementos(T& ss) {
	ss.push(42);
	ss.push(15);
	ss.pop();
	for (int i = 0; i < 100; i+=5)
		ss.push(i);
}

template <typename T>
void mostrar_elementos(const T& ss) {
	for (int i : ss)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main(int argc,char* argv[]) {
	static_stack<int>  ss_e;
	dynamic_stack<int> ss_d;

	anyadir_elementos(ss_e);
	anyadir_elementos(ss_d);

	mostrar_elementos(ss_e);
	mostrar_elementos(ss_d);

	return 0;
}
