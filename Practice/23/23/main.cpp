//
//  main.cpp
//  23
//
//  Created by Admin on 13.11.2020.
//

#include <iostream>
#include <iomanip>

#include "Header_1.h"
#include "Header_2.h"
#include "Header_3.h"

int main(){
	std::cout << 'n' << '\t' << "!n\n";
	for (int i = 1; i <= 10; i++)
		std::cout << i << '\t' << F(i) << '\n';
	std::cout << '\n';

	const double pi = 3.1415;
	std::cout << "x" << '\t' << "sin(x)\n";

	int k = 5;
	for (double x = 0; x <= pi / 4; x += pi / 180) {
		std::cout << x << "\t" << std::setprecision(4) << Func2(x, k) << "\n";
	}
	std::cout << '\n';

	std::cout << 'k' << '\t' << "C(k, 10)\n";

	for (int i = 1; i <= 10; i++)
		std::cout << i << '\t' << C(i, 10) << '\n';

	return 0;
}
