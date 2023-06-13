#include <tuple>
#include <type_traits>

#define TYPE_AT(TUP, IDX) std::remove_reference_t<decltype(*std::get<IDX>(TUP))>

int main() {
    std::tuple types = {static_cast<int*>(nullptr),
                        static_cast<double*>(nullptr),
                        static_cast<bool*>(nullptr)};

    TYPE_AT(types, 0) a;
    TYPE_AT(types, 1) b = 3.14;
    TYPE_AT(types, 2) c;

    a = 42;
    b = 13.1;
    c = false;

    static_assert(std::is_same_v<decltype(a), int>);
    static_assert(std::is_same_v<decltype(b), double>);
    static_assert(std::is_same_v<decltype(c), bool>);
}