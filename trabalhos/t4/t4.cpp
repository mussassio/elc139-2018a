#include <algorithm>
#include <iostream>
#include <string>
#include <omp.h>

class SharedArray
{
private:
	char *array;
	int index;
	int size;

public:
	SharedArray(int n) : size(n), index(0)
	{
		array = new char[size];
		std::fill(array, array + size, '-');
	}

	~SharedArray()
	{
		delete[] array;
	}

	void addChar(char c)
	{
#pragma omp critical //ponto critico
		{
			array[index] = c;
			spendSomeTime();
			index++;
		}
	}

	void addCharNotCritical(char c) //sem omp critical
	{
		array[index] = c;
		spendSomeTime();
		index++;
	}

	int countOccurrences(char c)
	{
		return std::count(array, array + size, c);
	}

	std::string toString()
	{
		return std::string(array, size);
	}


	void spendSomeTime()
	{
		for (int i = 0; i < 10000; i++)
		{
			for (int j = 0; j < 100; j++)
			{
			}
		}
	}
};

class ArrayFiller
{
private:
	static const int nThreads = 3;
	static const int nTimes = 60;
	SharedArray *array;

public:
	ArrayFiller()
	{
		array = new SharedArray(nTimes);
	}

	void fillArrayConcurrently(int example)
	{		
		run(nThreads, example);

	}

	void printStats()
	{
		std::cout << array->toString() << std::endl;
		for (int i = 0; i < nThreads; i++)
			std::cout << (char)('A' + i) << "="
			<< array->countOccurrences('A' + i) << " ";
		std::cout << std::endl;
	}

	~ArrayFiller()
	{
		delete array;
	}

private:
	void run(int n, int example)
	{
		int i;
		if (example == 1) //static
		{

#pragma omp parallel for schedule(static) num_threads(n) private(i)
			for (i = 0; i < nTimes; i++)
			{
				array->addChar('A' + omp_get_thread_num());
			}
		}
		if (example == 2) //dynamic
		{

#pragma omp parallel for schedule(dynamic, 20) num_threads(n) private(i)
			for (i = 0; i < nTimes; i++)
			{
				array->addChar('A' + omp_get_thread_num());
			}
		}
		if (example == 3) //guided
		{
#pragma omp parallel for schedule(guided) num_threads(n) private(i)
			for (i = 0; i < nTimes; i++)
			{
				array->addChar('A' + omp_get_thread_num());
			}

		}
		if (example == 4) //runtime
		{
#pragma omp parallel for schedule(runtime) num_threads(n) private(i)
			for (i = 0; i < nTimes; i++)
			{
				array->addChar('A' + omp_get_thread_num());
			}

		}
		if (example == 5) //not critical
		{

#pragma omp parallel for schedule(static) num_threads(n) private(i)
			for (i = 0; i < nTimes; i++)
			{
				array->addCharNotCritical('A' + omp_get_thread_num());
			}
		}
	}
};

int main()
{
	std::cout << "Osvaldo de Araujo Neto" << std::endl;
	

	std::cout << "Case 1: using schedule static" << std::endl;
	ArrayFiller m1;
	m1.fillArrayConcurrently(1);
	m1.printStats();

	std::cout << "Case 2: using schedule dynamic" << std::endl;
	ArrayFiller m2;
	m2.fillArrayConcurrently(2);
	m2.printStats();

	std::cout << "Case 3: using schedule guided" << std::endl;
	ArrayFiller m3;
	m3.fillArrayConcurrently(3);
	m3.printStats();

	std::cout << "Case 4: using schedule runtime" << std::endl;
	ArrayFiller m4;
	m4.fillArrayConcurrently(4);
	m4.printStats();

	std::cout << "Case 5: not using omp critical" << std::endl;
	ArrayFiller m5;
	m5.fillArrayConcurrently(5);
	m5.printStats();
	
	
	
	
	int c;
	std::cin >> c;

}
