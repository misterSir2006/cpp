#include <iostream>

class safe_c_array_t : public std::error_code {

private:
    int size; int* arr;

public:
    explicit safe_c_array_t (int n) { size = n; arr = new int[size]; }

    safe_c_array_t &operator=(const safe_c_array_t& arr2) {
        if (this != &arr2) {
                    delete[] arr;
                    size = arr2.size;
                    arr = new int[size];
                    for (int i = 0; i < size; i++) { arr[i] = arr2.arr[i]; }
        }
        return *this;
    }

    safe_c_array_t (const safe_c_array_t& origin) {
        size = origin.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) { arr[i] = origin.arr[i]; }
    }

    void fill() {
        for (int i = 0; i < size; i++) { arr[i] = i; }
    }
    
    void fill_random() {
        for (int i = 0; i < size; i++) { arr[i] = rand(); }
    }

    int &operator[](int k) { return arr[k]; }
    
    ~safe_c_array_t () { delete[]arr; }
};


int main() {
    
    safe_c_array_t arr = safe_c_array_t(16);
    safe_c_array_t arr2 = safe_c_array_t(arr);
    
    arr.fill(); arr2.fill();
    safe_c_array_t arr3 = arr2;
    
    std::cout << arr[13] << std::endl;
    std::cout << arr2[3] << std::endl;
    std::cout << arr3[7] << std::endl;

    safe_c_array_t rng_arr = safe_c_array_t(5);
    rng_arr.fill_random();
    
    std::cout << rng_arr[2] << std::endl;
    
    return 0;

}
