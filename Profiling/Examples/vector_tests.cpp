#include <memory>
#include <vector>
#include <Profiling/ScopedTimer.h>

static constexpr int SIZE=20000;

struct Foo {
    int m_x;
    int m_y;
    int m_z;
    Foo(int x, int y, int z):m_x(x), m_y(y), m_z(z){

    }
};

void emplace_back() {
    MEASURE_FUNCTION();
    std::vector<std::unique_ptr<Foo>> arr;
    arr.reserve(SIZE);

    for(int i = 0; i < SIZE; ++i){
        arr.emplace_back(new Foo(i, i + 1, i + 2));
    }
}

void push_back() {
    MEASURE_FUNCTION();
    std::vector<std::unique_ptr<Foo>> arr;
    arr.reserve(SIZE);

    for(int i = 0; i < SIZE; ++i){
        std::unique_ptr<Foo> p = std::make_unique<Foo>(i, i + 2, i + 3);
        arr.push_back(std::move(p));
    }
}

void assign() {
    MEASURE_FUNCTION();
    std::vector<std::unique_ptr<Foo>> arr (SIZE);

    for(int i = 0; i < SIZE; ++i){
        std::unique_ptr<Foo> p = std::make_unique<Foo>(i, i + 3, i + 4);
        arr[i]=std::move(p);
    }
}

int main(int argc, char** argv) {
    std::cout << "profiling emplace_back()" << std::endl;
    emplace_back();

    std::cout << "profiling push_back()" << std::endl;
    push_back();

    std::cout << "profiling assign()" << std::endl;
    assign();

    return 0;
}