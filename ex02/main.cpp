#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>

// int main()
// {
// 	srand(time(NULL));
// 	PmergeMe<std::vector<int> > myObject;

// 	for (int i = 0; i < 3000; i++)
// 	{
// 		myObject.push(rand() % 100);
// 	}
// 	clock_t start = clock();
// 	myObject.fj_sort(0, 3000);
// 	clock_t end = clock();
// 	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

//     std::cout << "Elapsed time: " << elapsedTime * 1000 << " seconds" << std::endl;




// 	// myObject.print();
// }

int main(int argc, char **argv)
{
	PmergeMe<std::vector<int> > vector;
	PmergeMe<std::deque<int> > deque;
	clock_t v_start, v_end, d_start, d_end;
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe n1 n2 n3 nxx" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{

		int n = atoi(argv[i]);
		if (n < 0)
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
		vector.push(n);
	}
	v_start = clock();
	vector.fj_sort(0, argc - 2);
	v_end = clock();
	std::cout << "Before :";
	for (int i = 1; i < argc; i++)
		std::cout << " " << argv[i];
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "After  :";
	vector.print();
	std::cout << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements in a vector: " << std::fixed << std::showpoint << static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC * 1000 << " us" << std::endl;
	d_start = clock();
	for (int i = 1; i < argc; i++)
	{
		int n = atoi(argv[i]);
		if (n < 0)
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
		deque.push(n);
	}
	deque.fj_sort(0, argc - 2);
	d_end = clock();
	// std::cout << "After  :";
	// deque.print();
	// std::cout << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements in a deque: " << static_cast<double>(d_end - d_start) / CLOCKS_PER_SEC * 1000 << " us" << std::endl;
	
}