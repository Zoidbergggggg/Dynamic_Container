#include <iostream>

void create_vector(int*& vec, const unsigned size, const int valueByDefault = 0)
{
	if (vec != nullptr)
	{
		delete[] vec;
	}
	vec = new int[size];
	for (int count = 0; count < size; count++) 
	{
		vec[count] = valueByDefault;
	}

}
int* create_vector(const unsigned size, const int valueByDefault = 0)
{
	int* vec = new int[size];
	for (int count = 0; count < size; count++) 
	{
		vec[count] = valueByDefault;
	}
	return vec;
}
void delete_vector(int* vec)
{
	if (vec != nullptr)
	{
		delete[] vec;
		vec = nullptr;
	}
}
void copy_vector(int* const to, const int* const from, const unsigned size)
{
	for (int count = 0; count < size; count++)
	{
		 to[count] = from[count];
	}
}
void push_back_in_vector(int*& vec, const unsigned size, const int newValue)
{
	int* copy = create_vector(size + 1);
	copy_vector(copy, vec, size);
	copy[size] = newValue;

	delete_vector(vec);
	vec = copy;

}
int& at_vector(int* const vec, const unsigned index)
{

	return vec[index];

}

void swap_items(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swap_items(int* const a, int* const b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap_items(int* const vec, const unsigned aIndex, const unsigned bIndex)
{
	int& a = at_vector(vec,aIndex);
	int& b = at_vector(vec,bIndex);
	swap_items(a, b);
}

void Print_Vec(const int* const vec, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

}

int main()
{
	size_t size = 5;
	int* vec1 = nullptr;
	create_vector(vec1, size, 2);

	int* vec2 = create_vector(size, 3);

	std::cout << "Vector 1 is: ";
	Print_Vec(vec1, size);
	std::cout << std::endl;
	std::cout << "Vector 2 is: ";
	Print_Vec(vec2, size);
	std::cout << "\n";

	copy_vector(vec1, vec2, size);
	std::cout << "Vector 1 is: ";
	Print_Vec(vec1, size);
	std::cout << std::endl;

	delete_vector(vec2);

	push_back_in_vector(vec1, size, 89);
	size++;
	
	std::cout << "Vector 1 is: ";
	Print_Vec(vec1, size);
	std::cout << std::endl;

	swap_items(vec1, 5, 3);
	std::cout << "Vector 1 is: ";
	Print_Vec(vec1, size);
	std::cout << std::endl;

	int* a = &at_vector(vec1, 3);
	int* b = &at_vector(vec1, 4);
	
	swap_items(a, b);

	std::cout << "Vector 1 is: ";
	Print_Vec(vec1, size);
	std::cout << std::endl;

	return 0;
}