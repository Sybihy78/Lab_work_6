#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>


void print(std::vector <int> vec) {
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}


int sum(const int& elem1, const int& elem2)
{
	return elem1 + elem2;
}


int main() {

	srand(time(NULL));

	std::cout << "Task 1: " << std::endl;

	std::vector <int> vec;
	for (int i = 0; i < 20; ++i) {
		vec.push_back(rand() % 20);
	}
	print(vec);

	using namespace std::placeholders;

	std::cout << "Count 10: " << std::count(vec.begin(), vec.end(), 10) << std::endl;
	
	std::cout << "Count <= 10: " <<
		std::count_if(vec.begin(), vec.end(), (std::bind(std::less_equal<int>(), _1, 10))) << std::endl;
	
	std::cout << "Find first > 10: " <<
		*std::find_if(vec.begin(), vec.end(), (std::bind(std::greater<int>(), _1, 10))) << std::endl;
	
	std::cout << "Find first != 1: " <<
		*std::find_if(vec.begin(), vec.end(), (std::bind(std::not_equal_to<int>(), _1, 1))) << std::endl;
	
	std::cout << "it == it->next: " << *std::adjacent_find(vec.begin(), vec.end()) << std::endl;
	
	std::cout << "all > 0: " <<
		std::all_of(vec.begin(), vec.end(), (std::bind(std::greater<int>(), _1, 0))) << std::endl;
	
	std::cout << "all > 5: " << 
		std::all_of(vec.begin(), vec.end(), (std::bind(std::greater<int>(), _1, 5))) << std::endl;
	
	std::cout << "any < 0: " <<
		std::any_of(vec.begin(), vec.end(), (std::bind(std::less<int>(), _1, 0))) << std::endl;
	
	std::cout << std::endl;
	std::cout << "Task 2: " << std::endl;

	std::vector <int> vec2;
	for (int i = 0; i < 20; ++i) {
		vec2.push_back(rand() % 20);
	}
	std::vector <int> vec3;
	for (int i = 0; i < 20; ++i) {
		vec3.push_back(rand() % 20);
	}
	print(vec2);
	print(vec3);

	std::cout << "vec2 == vec3: " <<
		std::equal(vec2.begin(), vec2.end(), vec3.begin(), vec3.end()) << std::endl;

	std::cout << "vec3 another vec2: " <<
		std::is_permutation(vec2.begin(), vec2.end(), vec3.begin(), vec3.end()) << std::endl;

	auto it1 = std::mismatch(vec2.begin(), vec2.end(), vec3.begin(), vec3.end());
	std::cout << "first elem vec3 another vec2: " << *it1.first << ' ' << *it1.second << std::endl;

	std::vector<int> vec4 = { 1, 2 };
	std::vector<int>::iterator it2 = std::search(vec3.begin(), vec3.end(), vec4.begin(), vec4.end());
	//std::cout << "{1, 2} in vec3: " << *it2 << std::endl;
	std::vector<int>::iterator it3 = std::search_n(vec2.begin(), vec2.end(), 3, 1);
	//std::cout << "{1, 1, 1} in vec2: " << *it3 << std::endl;
	
	int sum2 = 0;
	std::cout << "sum vec2: " << std::accumulate(vec2.begin(), vec2.end(), sum2) << std::endl;
	int sum3 = 0;
	std::cout << "sum vec3: " << std::accumulate(vec3.begin(), vec3.end(), sum3) << std::endl;
	
	std::vector<int> sum_data(vec2.size());
	std::transform(vec2.begin(), vec2.end(), vec3.begin(), sum_data.begin(), sum);
	std::cout << "sum elems vec2 + vec3: " << std::endl;
	print(sum_data);
	std::cout << std::endl;

	std::cout << "Task 3: " << std::endl;
	
	std::vector <int> vec5;
	for (int i = 0; i < 20; ++i) {
		vec5.push_back(5);
	}
	print(vec5);

	for (int i = 1; i < vec5.size(); ++(++i)) {
		vec5[i] = 8;
	}
	print(vec5);

	std::vector<int> copy_vec(vec5.size());
	std::copy(vec5.begin(), vec5.end(), copy_vec.begin());
	std::cout << "Copy_vec: " << std::endl;
	print(copy_vec);

	std::replace(copy_vec.begin(), copy_vec.end(), 5, 3);
	print(copy_vec);

	std::vector<int> last_vec;
	std::back_insert_iterator< std::vector<int>> back_it(last_vec);
	std::copy_if(copy_vec.begin(), copy_vec.end(), back_it, std::bind(std::less<int>(), _1, 5));
	std::cout << "Last_vec: " << std::endl;
	print(last_vec);
	
	for (int i = 0; i < last_vec.size(); ++i) {
		std::replace(last_vec.begin(), last_vec.end(), last_vec[i], i);
	}
	print(last_vec);
	
	std::reverse(last_vec.begin(), last_vec.end());
	print(last_vec);

	std::iter_swap(last_vec.begin(), last_vec.end() - 2);
	print(last_vec);

	std::iter_swap(last_vec.begin() + 1, last_vec.end() - 3);
	print(last_vec);

	std::rotate(last_vec.begin(), last_vec.begin() + last_vec.size() / 2, last_vec.end());
	print(last_vec);

	system("pause");
	return 0;
}

