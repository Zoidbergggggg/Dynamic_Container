#include <iostream>

class  MyVector
{
public:
	MyVector(const unsigned size, const int valueByDefault = 0)

	{
		m_size = size;
		vec = create_vector(size, valueByDefault);
	}

	~MyVector()
	{
		delete_vector(vec);
	}

	void push_back(const int newValue)
	{
		int* copy = create_vector(m_size + 1);
		copy_vector(copy, vec, m_size);
		copy[m_size] = newValue;

		delete_vector(vec);
		vec = copy;
		m_size = m_size + 1;

	}

	int& operator[](const unsigned index)
	{
		return vec[index];
	}

	void swap_items(const unsigned aIndex, const unsigned bIndex)
	{
		int temp = vec[aIndex];
		vec[aIndex] = vec[bIndex];
		vec[bIndex] = temp;
	}

	size_t Get_size()
	{
		return m_size;
	}

	MyVector(const MyVector&) = delete;
	MyVector operator =(const MyVector&) = delete;


private:
	size_t m_size;
	int* vec = nullptr;

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
};


void Print_Vec(MyVector& vec)
{
	for (int i = 0; i < vec.Get_size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	size_t size = 5;
	MyVector vec(size, 2);
	MyVector vec1(size, 3);

	std::cout << "Vector 1 is: ";
	Print_Vec(vec);
	std::cout << std::endl;
	std::cout << "Vector 2 is: ";
	Print_Vec(vec1);
	std::cout << "\n";

	vec.push_back(89);

	std::cout << "Vector 1 is: ";
	Print_Vec(vec);
	std::cout << std::endl;

	vec.swap_items(5, 3);
	std::cout << "Vector 1 is: ";
	Print_Vec(vec);
	std::cout << std::endl;

	return 0;
}