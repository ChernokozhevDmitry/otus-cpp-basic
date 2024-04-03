// Read files and prints top k word by frequency

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <chrono>
#include <thread>   // DCHE20240401
#include <mutex>    // DCHE20240401

const size_t TOPK = 10;

using Counter = std::map<std::string, std::size_t>;

std::mutex mymutex;     // DCHE20240401


std::string tolower(const std::string &str);

void count_words(std::istream& stream, Counter&);

void print_topk(std::ostream& stream, const Counter&, const size_t k);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: topk_words [FILES...]\n";
        return EXIT_FAILURE;
    }

    auto start = std::chrono::high_resolution_clock::now();
    Counter freq_dict;
    std::vector<std::thread> mythreads; 				// DCHE20240401 вектор потоков всех файлов 
    for (int i = 1; i < argc; ++i) {
// DCHE20240401 лямбда каждый файл в свой поток >>>>>
        std::thread file_thread([i, argv, &freq_dict]() {
            std::ifstream input{argv[i]};
            if (!input.is_open()) {
                std::cerr << "Failed to open file " << argv[i] << '\n';
                // return EXIT_FAILURE;       // DCHE20240402 return закомменчен, не знаю как ниже сделать, чтобы варнинга не было
            }
            count_words(input, freq_dict); // DCHE20240402 значение возвращается не при всех путях выполнения
        });
        mythreads.push_back(std::move(file_thread));
    }
// DCHE20240401 ждать завершения каждого
    for (auto& count : mythreads) {
        count.join();
    }
// DCHE20240401 <<<<<


    print_topk(std::cout, freq_dict, TOPK);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";
}

std::string tolower(const std::string &str) {
    std::string lower_str;
    std::transform(std::cbegin(str), std::cend(str),
                   std::back_inserter(lower_str),
                   [](unsigned char ch) { return std::tolower(ch); });
    return lower_str;
};

void count_words(std::istream& stream, Counter& counter) {
    std::for_each(std::istream_iterator<std::string>(stream),
                  std::istream_iterator<std::string>(),
// DCHE20240401 блокировка каждого                  
                  [&counter](const std::string &s) { /*++counter[tolower(s)]; });*/  // DCHE20240401  
                  auto count = tolower(s);				
                  std::lock_guard lock(mymutex);			
                  ++counter[count];					
                });
}
// DCHE20240401 <<<<<

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
        std::begin(words), std::begin(words) + k, std::end(words),
        [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
        std::begin(words), std::begin(words) + k,
        [&stream](const Counter::const_iterator &pair) {
            stream << std::setw(4) << pair->second << " " << pair->first
                      << '\n';
        });
}