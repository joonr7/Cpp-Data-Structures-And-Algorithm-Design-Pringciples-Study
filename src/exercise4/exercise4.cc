#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;
int main()
{
	// 시작: vector 로 구현했을 때
	std::vector<std::string> vec = {
		"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg", 
		"Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel", 
		"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonsp"
	};

	auto it = vec.begin(); // 상수 시간
	std::cout << "가장 최근 우승자: "  << *it << std::endl;

	it += 8;
	std::cout << "8년 전 우승자: " << *it <<std::endl;

	advance(it, -3);
	std::cout << "그후 3년 뒤 우승자: " << *it << std::endl;
	// 끝: 벡터로 구현했을 때


	// 시작: forward_list 로 구현했을 때
	std::forward_list<std::string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	std::cout << "가장 최근 우승자: " << *it1 << std::endl;

	advance(it1, 5); // 선형 시간
	std::cout << "5년 전 우승자:" << *it1 << std::endl;

	// // std::forward_list는 순방향으로 이동만 가능하므로, 아래 코드는 에러가 날 것이다.
	// // 실제로, Segmentation fault (core dumped) 발생함
	// advance(it1, -2);
	// std::cout << "3년 전 우승자:" << *it1 << std::endl;

	// 끝: forward_list 로 구현했을 때
}