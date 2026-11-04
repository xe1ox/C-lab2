#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <iomanip>
#include <numeric>
#include <deque>
#include <fstream>
#include <set>
#include <map>


void Task1_4(std::deque<int> D) {
    int half = D.size() / 2;

    std::cout << "The first half in reverse order: ";

    for (auto it = D.rbegin() + half; it != D.rend(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\nThe second half in reverse order: ";

    for (auto it = D.rbegin(); it != D.rbegin() + half; ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}



void Task2_7(std::vector<int>& V) {
    for (auto i = V.begin(); i != V.end(); ++i) {
        i = V.insert(++i, -1);
    }

    std::cout << "Result: ";

    for (auto i = V.begin(); i != V.end(); ++i) {
        std::cout << *i << " ";
    }

    std::cout << "\n";
}



void Task3_1(std::deque<int>& D) {
    auto middle = D.begin() + D.size() / 2;

    D.erase(middle);

    std::cout << "Result: ";

    for (auto i = D.begin(); i != D.end(); ++i) {
        std::cout << *i << " ";
    }

    std::cout << "\n";
}




bool Task4_7(const std::string& name, int K) {
    std::ofstream file(name);

    if (!file.is_open()) {
        return false;
    }

    std::fill_n(std::ostream_iterator<char>(file), K, '*');

    file.close();

    return true;
}




void Task5_6(const std::vector<int>& vector_values, std::list<int>& list_values) {
    const auto half_end = vector_values.begin() + static_cast<std::ptrdiff_t>(vector_values.size() / 2);
    const auto found = std::find_first_of(list_values.rbegin(), list_values.rend(), vector_values.begin(), half_end);
    if (found == list_values.rend()) {
        return;
    }
    const auto position = std::prev(found.base());
    list_values.insert(position, *position);
}



void Task6_6(std::list<int>& first_list, std::list<int>& second_list, int shift) {
    auto right_middle = first_list.begin();
    std::advance(right_middle, static_cast<int>(first_list.size()) - shift);
    std::rotate(first_list.begin(), right_middle, first_list.end());

    auto left_middle = second_list.begin();
    std::advance(left_middle, shift);
    std::rotate(second_list.begin(), left_middle, second_list.end());
}


void Task7_3(std::vector<int>& vector_values) {
    std::partial_sort(vector_values.begin(), vector_values.begin() + 3, vector_values.end(), std::greater<int>());
}


struct AverageOfPair {
    double operator()(int current, int previous) const {
        return (current + previous) / 2.0;
    }
};

std::vector<double> Task8_1(const std::list<int>& list_values) {
    std::vector<double> averages;
    std::adjacent_difference(list_values.begin(), list_values.end(),
    std::back_inserter(averages), AverageOfPair ());
    averages.erase(averages.begin());
    return averages;
}


int Task9_1(const std::vector<int>& base_vector, const std::vector<std::vector<int>>& vectors) {
    const std::set<int> base_set(base_vector.begin(), base_vector.end());
    int matching_count = 0;
    for (const std::vector<int>& current_vector : vectors) {
        const std::set<int> current_set(current_vector.begin(), current_vector.end());
        if (std::includes(current_set.begin(), current_set.end(), base_set.begin(), base_set.end())) {
            ++matching_count;
        }
    }
    return matching_count;
}


std::map<char, int> Task10_2(const std::vector<std::string>& words) {
    std::map<char, int> total_length_by_letter;
    for (std::vector<std::string>::const_iterator word_iterator = words.begin();
         word_iterator != words.end(); ++word_iterator) {
        total_length_by_letter[(*word_iterator)[0]] += static_cast<int>(word_iterator->size());
         }
    return total_length_by_letter;
}


int main() {

    std::cout << "Task 1.4\n";

    int count = 0;
    int number = 0;
    std::vector<int> numbers;

    std::cout << "Enter the number of values: ";

    if (!(std::cin >> count) || count <= 0 || count % 2 != 0) {
        std::cout << "Error: the quantity must be a positive even number.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } else {
        std::cout << "Enter " << count << " integers:\n";

        bool correctInput = true;

        for (int i = 0; i < count; i++) {
            if (!(std::cin >> number)) {
                std::cout << "Error: you must enter whole numbers.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                correctInput = false;
                break;
            }

            numbers.push_back(number);
        }

        if (correctInput) {
            std::deque<int> D(numbers.begin(), numbers.end());
            Task1_4(D);
        }
    }




    std::cout << "\nTask 2.7\n";
    std::cout << "Enter the number of elements: ";

    if (!(std::cin >> count) || count <= 0) {
        std::cout << "Error: enter a positive integer.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } else {
        std::cout << "Enter " << count << " integers:\n";

        bool correctInput = true;

        for (int j = 0; j < count; j++) {
            if (!(std::cin >> number)) {
                std::cout << "Error: enter integers only.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                correctInput = false;
                break;
            }

            numbers.push_back(number);
        }

        if (correctInput) {
            std::vector<int> V(numbers.begin(), numbers.end());
            Task2_7(V);
        }
    }




    std::cout << "\nTask 3.1\n";
    std::cout << "Enter the number of elements: ";

    if (!(std::cin >> count) || count < 3 || count % 2 == 0) {
        std::cout << "Error: enter an odd number greater than or equal to 3.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } else {
        std::cout << "Enter " << count << " integers:\n";

        bool correctInput = true;

        for (int j = 0; j < count; j++) {
            if (!(std::cin >> number)) {
                std::cout << "Error: enter integers only.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                correctInput = false;
                break;
            }

            numbers.push_back(number);
        }

        if (correctInput) {
            std::deque<int> D(numbers.begin(), numbers.end());
            Task3_1(D);
        }
    }




    std::cout << "\nTask 4.7\n";
    std::cout << "Enter the file name: ";

    std::string name;
    int K = 0;

    std::cin >> name;

    std::cout << "Enter the number of characters: ";

    std::istream_iterator<int> input(std::cin);
    std::istream_iterator<int> end;

    if (input == end || *input <= 0) {
        std::cout << "Error: enter a positive integer.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } else {
        K = *input;

        if (Task4_7(name, K)) {
            std::cout << "File created successfully.\n";
        } else {
            std::cout << "Error: cannot open the file.\n";
        }
    }


    std::cout << "\nTask 5.6\n";

    bool is_input_correct = true;
    int vector_size = 0;
    int list_size = 0;
    std::vector<int> vector_values;
    std::list<int> list_values;

    std::cout << "Enter the vector size: ";
    if (!(std::cin >> vector_size) || vector_size <= 0 || vector_size % 2 != 0) {
        is_input_correct = false;
    }

    for (int i = 0; is_input_correct && i < vector_size; ++i) {
        int value = 0;
        std::cout << "Enter vector element " << i + 1 << ": ";
        if (!(std::cin >> value)) {
            is_input_correct = false;
        } else {
            vector_values.push_back(value);
        }
    }

    if (is_input_correct) {
        std::cout << "Enter the list size: ";
        if (!(std::cin >> list_size) || list_size < 0) {
            is_input_correct = false;
        }
    }

    for (int i = 0; is_input_correct && i < list_size; ++i) {
        int value = 0;
        std::cout << "Enter list element " << i + 1 << ": ";
        if (!(std::cin >> value)) {
            is_input_correct = false;
        } else {
            list_values.push_back(value);
        }
    }

    if (is_input_correct) {
        Task5_6(vector_values, list_values);
        std::cout << "Resulting list:";
        for (int value : list_values) {
            std::cout << " " << value;
        }
        std::cout << "\n";
    } else {
        std::cout << "Error: enter correct numbers.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }



    std::cout << "\nTask 6.6\n";

    int shift = 0;
    int first_size = 0;
    int second_size = 0;
    std::list<int> first_list;
    std::list<int> second_list;

    std::cout << "Enter the shift K (from 1 to 9): ";
    if (!(std::cin >> shift) || shift <= 0 || shift >= 10) {
        is_input_correct = false;
    }

    if (is_input_correct) {
        std::cout << "Enter the size of the first list (at least 10): ";
        if (!(std::cin >> first_size) || first_size < 10) {
            is_input_correct = false;
        }
    }

    for (int i = 0; is_input_correct && i < first_size; ++i) {
        int value = 0;
        std::cout << "Enter element " << i + 1 << " of the first list: ";
        if (!(std::cin >> value)) {
            is_input_correct = false;
        } else {
            first_list.push_back(value);
        }
    }

    if (is_input_correct) {
        std::cout << "Enter the size of the second list (at least 10): ";
        if (!(std::cin >> second_size) || second_size < 10) {
            is_input_correct = false;
        }
    }

    for (int i = 0; is_input_correct && i < second_size; ++i) {
        int value = 0;
        std::cout << "Enter element " << i + 1 << " of the second list: ";
        if (!(std::cin >> value)) {
            is_input_correct = false;
        } else {
            second_list.push_back(value);
        }
    }

    if (is_input_correct) {
        Task6_6(first_list, second_list, shift);
        std::cout << "First list after the right shift:";
        for (int value : first_list) {
            std::cout << " " << value;
        }
        std::cout << "\nSecond list after the left shift:";
        for (int value : second_list) {
            std::cout << " " << value;
        }
        std::cout << "\n";
    } else {
        std::cout << "Error: enter correct numbers (K from 1 to 9, each list must have at least 10 elements).\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }



    std::cout << "\nTask 7.3\n";
    std::cout << "Enter the vector size (at least 3): ";
    if (!(std::cin >> vector_size) || vector_size < 3) {
        is_input_correct = false;
    }

    for (int i = 0; is_input_correct && i < vector_size; ++i) {
        int value = 0;
        std::cout << "Enter vector element " << i + 1 << ": ";
        if (!(std::cin >> value)) {
            is_input_correct = false;
        } else {
            vector_values.push_back(value);
        }
    }

    if (is_input_correct) {
        Task7_3(vector_values);
        std::cout << "Three largest elements in descending order: ";
        std::copy(vector_values.begin(), vector_values.begin() + 3,
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";
    } else {
        std::cout << "Error: enter correct numbers (the vector size must be at least 3).\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }



    std::cout << "\nTask 8.1\n";

    std::cout << "Enter the list size (at least 2): ";
    if (!(std::cin >> list_size) || list_size < 2) {
        is_input_correct = false;
    }

    for (int i = 0; is_input_correct && i < list_size; ++i) {
        int value = 0;
        std::cout << "Enter list element " << i + 1 << ": ";
        if (!(std::cin >> value)) {
            is_input_correct = false;
        } else {
            list_values.push_back(value);
        }
    }

    if (is_input_correct) {
        const std::vector<double> averages = Task8_1(list_values);
        std::cout << "Averages of adjacent pairs:";
        std::cout << std::fixed << std::setprecision(1);
        for (double average : averages) {
            std::cout << " " << average;
        }
        std::cout << "\n";
    } else {
        std::cout << "Error: enter correct numbers (the list size must be at least 2).\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }


    std::cout << "\nTask 9.1\n";

    int base_size = 0;
    int vectors_count = 0;
    std::vector<int> base_vector;
    std::vector<std::vector<int>> vectors;

    std::cout << "Enter the size of vector V0 (at least 1): ";
    if (!(std::cin >> base_size) || base_size <= 0) {
      is_input_correct = false;
    }

    for (int i = 0; is_input_correct && i < base_size; ++i) {
      int value = 0;
      std::cout << "Enter element " << i + 1 << " of vector V0: ";
      if (!(std::cin >> value)) {
        is_input_correct = false;
      } else {
        base_vector.push_back(value);
      }
    }

    if (is_input_correct) {
      std::cout << "Enter the number of vectors N (at least 1): ";
      if (!(std::cin >> vectors_count) || vectors_count <= 0) {
        is_input_correct = false;
      }
    }

    for (int i = 0; is_input_correct && i < vectors_count; ++i) {
      int current_size = 0;
      std::cout << "Enter the size of vector V" << i + 1 << " (at least "
                << base_size << "): ";
      if (!(std::cin >> current_size) || current_size < base_size) {
        is_input_correct = false;
      } else {
        std::vector<int> current_vector;
        for (int j = 0; is_input_correct && j < current_size; ++j) {
          int value = 0;
          std::cout << "Enter element " << j + 1 << " of vector V" << i + 1
                    << ": ";
          if (!(std::cin >> value)) {
            is_input_correct = false;
          } else {
            current_vector.push_back(value);
          }
        }
        if (is_input_correct) {
          vectors.push_back(current_vector);
        }
      }
    }

    if (is_input_correct) {
      std::cout << "Number of vectors containing all elements of V0: " << Task9_1(base_vector, vectors) << "\n";
    } else {
      std::cout << "Error: enter correct numbers (sizes must be positive, and every vector must be at least as large as V0).\n";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }



    std::cout << "\nTask 10.2\n";

    int words_count = 0;
    std::vector<std::string> words;

    std::cout << "Enter the number of words (at least 1): ";
    if (!(std::cin >> words_count) || words_count <= 0) {
        is_input_correct = false;
    }

    for (int i = 0; is_input_correct && i < words_count; ++i) {
        std::string word;
        std::cout << "Enter word " << i + 1 << " (uppercase English letters): ";
        if (!(std::cin >> word) || !std::all_of(word.begin(), word.end(),[](char letter) { return letter >= 'A' && letter <= 'Z'; })) {
            is_input_correct = false;
        } else {
            words.push_back(word);
        }
    }

    if (is_input_correct) {
        const std::map<char, int> total_length_by_letter = Task10_2(words);
        std::cout << "Total length of words by first letter:\n";
        for (std::map<char, int>::const_iterator letter_iterator = total_length_by_letter.begin();
            letter_iterator != total_length_by_letter.end(); ++letter_iterator) {
                std::cout << letter_iterator->first << " " << letter_iterator-> second << "\n";
            }
    } else {
        std::cout << "Error: enter correct data (the number of words must be positive, words must consist of uppercase English letters).\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    return 0;
}