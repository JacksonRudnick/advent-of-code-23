#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

std::string nums[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int get_value(std::string line) {
	//loop through string and find all nums as words
	//replace words with nums
	//find first and last num

	std::string num = "";

	for (int i = 0; i < line.length(); i++) {
		for (int b = i; b < line.length(); b++) {
			for (int x = 0; x < 9; x++) {
				if (line.substr(i, b-i) == nums[x]) {
					line = line.substr(0, i) + std::to_string(x+1) + line.substr(b);
					//std::cout << line << std::endl;
					break;
				}
			}
		}
	}
	
	for (int i = 0; i < line.length(); i++) {
		if (isdigit(line[i])) {
			num+=line[i];
			break;
		}
	}

	for (int i = line.length(); i >= 0; i--) {
		if (isdigit(line[i])) {
			num+=line[i];
			break;	
		}
	}

	return std::stoi(num);
}

int main() {
	int sum = 0;

	std::string line;
	std::fstream infile("./input.txt");

	int i = 0;
	
	while(std::getline(infile, line)) {
		i++;
		int n = get_value(line);
		sum += n;
		std::cout << "i:: " << i << " n:: " << n << " sum:: " << sum << std::endl;

	}

	std::cout << sum << std::endl;

	return 0;
}