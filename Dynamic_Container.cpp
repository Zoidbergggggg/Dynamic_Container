#include <iostream>

class  MyVector
{
public:
	MyVector(const unsigned size, const int valueByDefault = 0)

	{
		m_size = size;
		capacity = size;
		vec = create_vector(size, valueByDefault);
	}
	MyVector(const MyVector& copyVector)
	{
		m_size = copyVector.m_size;
		capacity = m_size;
		vec = create_vector(m_size);
		copy_vector(vec, copyVector.vec, m_size);
	}
	MyVector& operator=(const MyVector& copyVector)
	{
		delete_vector(vec);
		m_size = copyVector.m_size;
		capacity = m_size;
		vec = create_vector(m_size);
		copy_vector(vec, copyVector.vec, m_size);
		return *this;
	}

	~MyVector()
	{
		delete_vector(vec);
	}

	void push_back(const int newValue)
	{
		if (m_size >= capacity)
		{
			capacity *= 2;
			int* copy = create_vector(capacity);
			copy_vector(copy, vec, m_size);
			delete_vector(vec);
			vec = copy;
			std::cout << "Now your capacity is " << capacity << "\n\n";
		}
		vec[m_size] = newValue;
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

	MyVector(MyVector&&) = delete;
	MyVector& operator= (MyVector&&) = delete;


private:
	size_t m_size;
	int* vec = nullptr;
	size_t capacity;

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
	vec.push_back(15);

	std::cout << "Vector 1 is: ";
	Print_Vec(vec);
	std::cout << std::endl;

	vec.swap_items(5, 3);
	std::cout << "Vector 1 is: ";
	Print_Vec(vec);
	std::cout << std::endl;

	MyVector vec2(vec);

	std::cout << "Your new vector is: ";
	Print_Vec(vec2);
	std::cout << std::endl;

	vec1 = vec2;
	std::cout << "Vector 1: ";
	Print_Vec(vec1);
	std::cout << std::endl;

	return 0;
}