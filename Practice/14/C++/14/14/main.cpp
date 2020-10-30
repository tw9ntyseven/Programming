#include <iostream>

int Elevate(int a) {
	if (a == 0)
		return 0;

	int var = 2;
	int count = 1;
	while (var < a)
	{
		var *= 2;
		count++;
	}
	return count;
}

int main() {
	int num;
	std::cin >> num;
	std::cout << Elevate(num) << '\n';

	system("pause");
	return 0;
}