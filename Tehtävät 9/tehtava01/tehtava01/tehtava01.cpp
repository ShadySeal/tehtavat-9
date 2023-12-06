#include <iostream>
#include <new>
#include <cstdlib>

int main() {
    const size_t allocation_size = 1000000;
    size_t total_allocated = 0;

    // new
    try {
        while (true) {
            int* cpp_ptr = new int[allocation_size];
            total_allocated += allocation_size;
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Muistinvaraus epäonnistui: " << e.what() << std::endl;
        std::cerr << "Onnistuneesti varattu muisti: " << total_allocated << std::endl;
    }

    total_allocated = 0;

    // malloc
    while (1) {
        int* c_ptr = (int*)malloc(allocation_size * sizeof(int));
        if (c_ptr == NULL) {
            fprintf(stderr, "Muistinvaraus epäonnistui\n");
            break;
        }
        total_allocated += allocation_size;
    }

    printf("Onnistuneesti varattu muisti: %lu\n", total_allocated);

    return 0;
}
