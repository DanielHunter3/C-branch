#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stdlib.h>
#include <Windows.h>

class Math {
private:
	double x, y;
public:
	Math(double x, double y) {
		this->x = x;
		this->y = y;
	}

	double math_operations(std::string symbal) {
		if (symbal == "+") return x + y;
		else if (symbal == "-") return x - y;
		else if (symbal == "*") return x * y;
		else if (symbal == "/") {
			if (y == 0.0) {
				std::cout << "The Y is 0";
				abort();
			}
			else return x / y;
		}
		else if (symbal == "^") return powf(x, y);
		else {
			std::cout << "This is not math operation: " << symbal;
			abort();
		}
	}
};

std::tuple<std::string, bool> in_vector(std::vector<std::string> vec, std::string symbal) {
	for (auto& i : vec) { if (i == symbal) { return std::make_tuple(symbal, true); } }
	return std::make_tuple("", false);
}

int main() {
	double x = 0.0, y = 0.0;
	std::string symbal;
	std::vector<std::string> vec{"+", "-", "*", "/", "^"};

	std::cout << "Enter a first number: ";
	std::cin >> x;

	std::cout << "Enter a math symbal: ";
	std::cin >> symbal;

	std::string result = "";
	bool is_bool = false;
	std::tie(result, is_bool) = in_vector(vec, symbal);

	if (is_bool == false) {
		std::cout << "This is not math operation: " << symbal;
		abort();
	}

	std::cout << "Enter a second number: ";
	std::cin >> y;

	Math math(x, y);
	std::cout << "Result: " << math.math_operations(result) << "\n\n";

	system("pause");
}