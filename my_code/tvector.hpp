#ifndef tvector_hpp
#define tvector_hpp

#include <stdio.h>

const int DEF_CAPACITY = 10;

template <typename T>
class MyVec {
public:
	MyVec() {
		sz = 0;
		capacity = DEF_CAPACITY;
		data = new T[capacity];
	}
	
	MyVec(int size, T val) {
		sz = size;
		capacity = std::max(size, DEF_CAPACITY);
		data = new T[capacity];
		for (int i = 0; i < sz; i++) {
			data[i] = val;
		}
	}
	
	// copy control:
	MyVec(const MyVec<T>& v2) {
		sz = v2.sz;
		capacity = v2.capacity;
		data = new T[capacity];
		for (int i = 0; i < sz; i++) {
			data[i] = v2.data[i];
		}
	}
	
	~MyVec() {
		if (data) { delete[] data; }
	}
	
	MyVec& operator=(const MyVec<T>& v2) {
		if (&v2 != this) {
			sz = v2.sz;
			capacity = v2.capacity;
			if (data) { delete[] data; }
			data = new T[capacity];
			for (int i = 0; i < sz; i++) {
				data[i] = v2.data[i];
			}
		}
		return *this;
	}
	
	void push_back(T val) {
		if (sz == capacity) {
			capacity *= 2;
			T* new_data = new T[capacity];
			for (int i = 0; i < sz; i++) {
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
		}
		data[sz] = val;
		++sz;
	}
	
	int size() const { return sz; }
	
	T operator[](int i) const { return data[i]; }
	
	T& operator[](int i) { return data[i]; }
	
private:
	T* data;
	int sz;
	int capacity;
};

template <typename T>
void print_vector(const MyVec<T>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
	if (v1.size() == v2.size()) {
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] != v2[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}


#endif /* tvector_hpp */
