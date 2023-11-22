#include "OpenMP.hpp"
#include "Heap.hpp"

void runOpenMP() {
    hello_world();
    cal_sum();
    cal_max();
}

void runHeap() {
    printf("\nStart runHeap()\n");
    int data_size = 12;
    int* data = new int[data_size];
    for (int i = 0; i < data_size; ++i) {
        data[i] = rand() % data_size;
    }
    auto *hp = new Heap<int>();
    for (int i = 0; i < data_size; ++i) {
        hp->push(data[i]);
    }

    // Sort these values using stl
    std::vector<int> vect(data, data + data_size);
    std::sort(vect.begin(), vect.end());
    std::cout << hp->to_string() << std::endl;

    for (int i = 0; i < data_size; ++i) {
        // Compare the pop result with the value sorted by stl
        // If the two required functions are correct, the assertion should pass
        std::cout << "Running pop" << std::endl;
        assert(vect[i] == hp->pop());
    }
    printf("\nStart runHeap(): assert pass!\n");
}
int main(int argc, char* argv[])
{
    runOpenMP();
    runHeap();
}

//cd "/Users/gabrielheinrichs/Desktop/CS_223/MA4_start_code/" && cmake --build Build_Folder && cd Build_folder && ./MA4 && cd -
//ignore this line, it is just so I can reference it later in my terminal in vscode