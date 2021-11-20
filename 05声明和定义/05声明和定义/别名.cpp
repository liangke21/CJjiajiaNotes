#include <iostream>






int main881()
{
	using std::cout;
	using std::endl;
	cout << "你愁啥" << endl;

	return 0;
}
//示例： using 声明成员的声明
int main882() {

	// C++11
	using counter = long;

	// C++03 equivalent:
	// typedef long counter;  //同上等效

	return 0;
}
int main883() {

	// C++11
	using fmtfl = std::ios_base::fmtflags;

	// C++03 equivalent:
	// typedef std::ios_base::fmtflags fmtfl;

	fmtfl fl_orig = std::cout.flags();
	fmtfl fl_hex = (fl_orig & ~std::cout.basefield) | std::cout.showbase | std::cout.hex;
	// ...
	std::cout.flags(fl_hex);

    return 0;
	
}


//示例

#include <stdlib.h>
#include <new>

//我的分配
template <typename T> struct MyAlloc {
    typedef T value_type;

    MyAlloc() { }
    template <typename U> MyAlloc(const MyAlloc<U>&) { }

    bool operator==(const MyAlloc&) const { return true; }
    bool operator!=(const MyAlloc&) const { return false; }

    T* allocate(const size_t n) const {
        if (n == 0) {
            return nullptr;
        }

        if (n > static_cast<size_t>(-1) / sizeof(T)) {
            throw std::bad_array_new_length();
        }

        void* const pv = malloc(n * sizeof(T));

        if (!pv) {
            throw std::bad_alloc();
        }

        return static_cast<T*>(pv);
    }

    void deallocate(T* const p, size_t) const {
        free(p);
    }
};

#include <vector>
using MyIntVector = std::vector<int, MyAlloc<int>>;  //vector接收 不同大小的值数组

#include <iostream>

int main884()
{
   
    MyIntVector foov = { 1701, 1764, 1664 };
  //   std::vector<int, MyAlloc<int>> foov = { 1701, 1764, 1664 };  //等效相同
    for (auto a : foov) std::cout << a << " ";
    std::cout << "\n";

    return 0;
}