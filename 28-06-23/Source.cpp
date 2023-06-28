#include<iostream>
//#include<vector>
#include<string>
//#include<list>
//#include<map>
#include<array>
#include<iterator>

//Variadic template->tuple

template <typename Type, int _size>
class MyClass {
public:

	MyClass() {}
	
	class iterator {

	public:
		iterator() = delete;
		iterator(Type* data) : data_(data){ }

			iterator & operator++() {
			data_++;
			return *this;
		}
		iterator& operator++(int) {
			iterator tmp(*this);
			data_++;
			return tmp;
		}
		Type& iterator operator*() {
			return *data_;
		}
		iterator begin() {
			return iterator(data_);
		}
		iterator end() {
			return iterator(data_ + size_);
		}
		bool operator!=(const iterator& obj)const {
			return this->data_ != obj.data_;
		}

		
		bool operator==(const iterator & obj)const {
			return ! this->operator==(obj);
			//
		}

	private:
		Type* data_;
	};

	int size()const {
		return size_;
	}

	const Type& operator[](int i)const {
		return data_[i];
	}
	 Type& operator[](int i) {
		return data_[i];
	}

private:
	Type data_[_size];
	const int size_{_size};
};

void f01(MyClass<int, 10> a) {
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << ' ';
	}
}



int main() {
	//std::vector<int>_vec{9,8,7};
	//std::list<int>_list{1,2,3};
	MyClass<int, 10>a;
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << ' ';
		a[i] = i + 1;
	}

	f01(a);
	int arr[10];

	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << ' ';
		a[i] = i + 1;
	}
	for (const auto& el : arr) {
		std::cout << el << ' ';
	}
	std::array<int,10> arrObj;

	for (size_t i = 0; i < std::size(arrObj); i++)
	{
		std::cout << a[i] << ' ';
		a[i] = i + 1;
	}
	/*for (const auto& el : a) {
		std::cout << el << ' ';
	}*/
	//std::array<int,10>::iterator it
	for (auto it = arrObj.begin(); it != arrObj.end(); ++it) {
		const auto& el = *it;
		//it->operator[](0); it->at(0);
		std::cout << el << ' ';
	}

	/*std::array<int, 6> arrA;
	srand(time(NULL));
	for (size_t i = 0; i < size(arrA); i++)
	{
		arr[i] = rand() % 101;
		std::cout << arr[i] << ' ';
	}
	std::cout<<"\n\n" << arrA.size();*/




	return 0;
}