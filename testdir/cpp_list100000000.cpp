#include <iostream>
#include <list>
#include <ctime>
#include <iterator> // For std::advance

int main() {
    size_t n_inserts = 100000000;
    double time_spent = 0;

    // Create the list
    std::list<char> List;
    // No need to reserve capacity for std::list

    clock_t start = clock();

    for (size_t i = 0; i < n_inserts / 4; i++) {
        // Prepend (insert at the beginning)
        List.push_front('@');

        // Append (push back)
        List.push_back('D');

        // Insert at 1/4
        size_t insert_pos_1_4 = i / 4; // Use i/4 like in your program
        if (insert_pos_1_4 < List.size()) { // Safety check
            auto it = List.begin();
            std::advance(it, insert_pos_1_4);
            List.insert(it, '0');
        }

        // Insert at 3/4
        size_t insert_pos_3_4 = (i / 4) * 3; // Use (i/4)*3 like in your program
        if (insert_pos_3_4 < List.size()) { // Safety check
            auto it = List.begin();
            std::advance(it, insert_pos_3_4);
            List.insert(it, 'D');
        }
    }

    clock_t end = clock();
    time_spent = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Time for " << n_inserts << " : " << time_spent << " seconds\n";

    return 0;
}