#include <iostream>
#include <vector>
#include <ctime>

int main() {
    size_t n_inserts = 100000000;
    double time_spent = 0;

    // Create the vector with an initial capacity
    std::vector<char> Vector;
    Vector.reserve(5); // Reserve initial capacity (optional, similar to your initial size)

    clock_t start = clock();

    for (size_t i = 0; i < n_inserts / 4; i++) {
        // Prepend (insert at the beginning)
        Vector.insert(Vector.begin(), '@');

        // Append (push back)
        Vector.push_back('D');

        // Insert at 1/4
        size_t insert_pos_1_4 = Vector.size() / 4;
        if (insert_pos_1_4 < Vector.size()) { // Safety check
            Vector.insert(Vector.begin() + insert_pos_1_4, '0');
        }

        // Insert at 3/4
        size_t insert_pos_3_4 = (Vector.size() * 3) / 4;
        if (insert_pos_3_4 < Vector.size()) { // Safety check
            Vector.insert(Vector.begin() + insert_pos_3_4, 'D');
        }
    }

    clock_t end = clock();
    time_spent = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Time for " << n_inserts << " : " << time_spent << " seconds\n";

    return 0;
}