#include <iostream>
#include <thread>
#include <vector>
// stvorenia futsii dlia vvivodu nomer ta ryadke
void print(int n, const std::string& str) {
	std::cout << n << ":" << str << std::endl;
}
int main() {
	// stvorenya masivu
	std::vector<std::string> s = {
	"Educative.blog",
	"Educative",
	"courses",
	"are great"
	};
	// 
	std::vector<std::thread> threads;
	// bagatopotochne vivedenia poperedniogo masivu
	for (int i = 0; i < s.size(); i++) {
		threads.push_back(std::thread(print, i, s[i]));
	}
	for (auto& th : threads) {
	    // zatrimka golovnoi programi doki "th" ne zavershit svoyu zdzchu
		th.join();
	}
	return 0;
}
