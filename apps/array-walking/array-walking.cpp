#include "dsa/utils/stopwatch.h"

#include <cstdio>
#include <filesystem>

namespace fs = std::filesystem;

const char* task_color = "\033[36m"; // blue
const char* highlight_color = "\033[32m"; // green
const char* error_color = "\033[91m"; // red
const char* end_color = "\033[0m";

void error(const char* msg) {
    std::cout << error_color << "ERROR: " << msg << end_color << std::endl;
}

void display_usage(const char* executablePath)
{
    try {
        fs::path ep(executablePath);

        std::cout
            << "Usage:\n\t"
            << ep.filename()
            << " <row_count> <column_count>\n";
    }
    catch (...) {
        std::cout << "Cannot parse path from argv[0]";
    }
}

class benchmark {
public:
    const size_t rows = 0;
    const size_t columns = 0;
    int* arr = nullptr;

    benchmark(size_t rows, size_t columns)
        : rows(rows), columns(columns)
    {
        size_t total_size = rows * columns;

        std::cout << task_color
                  << "Allocating an array of "
                  << total_size
                  << " elements..."
                  << end_color
                  << std::endl;

        arr = new int[total_size];
    }

    ~benchmark() {
        delete [] arr;
    }

    benchmark(const benchmark&) = delete;
    benchmark& operator=(const benchmark&) = delete;
};

using benchmark_fn = void (*)(int* arr, size_t rows, size_t columns);

void run_benchmark(benchmark& bm, benchmark_fn fn, const char* msg)
{
    std::cout << "\n" << task_color << msg << end_color << std::endl;

    stopwatch sw;
    sw.start();

    fn(bm.arr, bm.rows, bm.columns);

    sw.stop();

    std::cout
        << "    * execution took "
        << highlight_color
        << sw
        << end_color
        << std::endl;
}

void initialize_array(int* arr, size_t rows, size_t columns)
{
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < columns; ++c)
            arr[columns * r + c] = static_cast<int>(r);
}

void walk_by_rows(int* arr, size_t rows, size_t columns)
{
    size_t sum = 0;

    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < columns; ++c)
            sum = (sum + arr[columns * r + c]) & 0xFFFF;

    std::cout << "    * result is " << sum << std::endl;
}

void walk_by_columns(int* arr, size_t rows, size_t columns)
{
    size_t sum = 0;

    for (size_t c = 0; c < columns; ++c)
        for (size_t r = 0; r < rows; ++r)
            sum = (sum + arr[columns * r + c]) & 0xFFFF;

    std::cout << "    * result is " << sum << std::endl;
}

int main(int argc, char* argv[])
{
    size_t rows;
    size_t columns;

    // Verify the number of arguments
    if(argc < 3) {
        display_usage(argv[0]);
        return 1;
    }

    // Parse input
    if( ! sscanf(argv[1], "%zu", &rows) || ! sscanf(argv[2], "%zu", &columns) ) {
        error("Cannot convert command line arguments to size_t");
        return 2;
    }

    try {
        benchmark bm(rows, columns);
        run_benchmark(bm, initialize_array, "Initializing the elements of the array");
        run_benchmark(bm, walk_by_rows, "Iterating by rows and then columns");
        run_benchmark(bm, walk_by_columns, "Iterating by columns and then rows");

    }
    catch(std::bad_alloc&) {
        error("Failed to allocate memory!");
        return 3;
    }
    catch(...) {
        error("Exception caught!");
        return 4;
    }
}
