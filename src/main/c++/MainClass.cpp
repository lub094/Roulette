#include <iostream>
#include "Roulette.cpp"

using namespace std;

class MainClass {
public:
    static void main(string args[] = nullptr) {
        Roulette roulette(10);
        roulette.spin(50, true);
    }
};

int main() {
    srand(time(nullptr));
    MainClass::main();
    return 0;
}
