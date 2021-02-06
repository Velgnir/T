#include <iostream>
#include <thread>
#include <vector>
// створення процедури виводу номеру та рядка, яка далі буде вкористовуватися в роботі з масивом
void print(int n, const std::string& str) {
	std::cout << n << ":" << str << std::endl;
}
int main() {
	// створення масиву
	std::vector<std::string> s = {
	"Educative.blog",
	"Educative",
	"courses",
	"are great"
	};
	// 
	std::vector<std::thread> threads;
	// багатопотчне виведення попереднього масиву
	for (int i = 0; i < s.size(); i++) {
		threads.push_back(std::thread(print, i, s[i]));
	}
	for (auto& th : threads) {
	    // гальмування головної функції доки "th" не закінчить свій процес
		th.join();
	}
	return 0;
}