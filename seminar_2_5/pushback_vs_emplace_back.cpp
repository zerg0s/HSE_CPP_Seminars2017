#include <vector>

struct Item {
    int a, b, c;
    Item(int a, int b, int c) :a(a), b(b), c(c) {}
};

// emplace умеет вызывать конструктор в недрах вектора, не создавая лишних копий.

int main_push_emplace() {
    std::vector<Item> x;
    // x.push_back(1, 2, 3);    <- не скомпилируется!
    x.emplace_back(1, 2, 3);
    return 0;
}