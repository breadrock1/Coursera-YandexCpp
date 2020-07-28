#include "iostream"

using namespace std;

uint64_t CalcSumCapacity(uint16_t &W, uint16_t &H, uint16_t &L) {
    return (uint64_t)W * (uint64_t)H * (uint64_t)L;
}

int main() {

    uint32_t NumBlocks = 0;
    uint64_t SumCapacity = 0;
    uint16_t Density = 0, Width = 0, Height = 0, Length = 0;

    cin >> NumBlocks >> Density;

    for (size_t i = 0; i < NumBlocks; ++i) {
        cin >> Width >> Height >> Length;
        SumCapacity += CalcSumCapacity(Width, Height, Length) * Density;
    }

    cout << SumCapacity;

    return 0;
}
