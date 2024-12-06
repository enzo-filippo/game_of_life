#include "functions/hello_world.hpp"

#include <cstring>
#include <chrono>
#include <random>

void header( )
{
    printf("(II)\n");
#if defined (__APPLE__)
    printf("(II) Stage 1 - The compiler, your friend on MacOS\n");
#elif defined (__linux__)    
    printf("(II) Stage 1 - The compiler, your friend on Linux\n");
#else
    printf("(II) Stage 1 - The compiler, your friend on Windows\n");
#endif
    printf("(II) Bertrand LE GAL - bertrand.legal@enseirb-matmeca.fr\n");
    printf("(II)\n");

#if defined (__clang__)    
    printf("(II) Code compiled with LLVM (%d.%d.%d) ", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined (__GNUC__)
    printf("(II) Code compiled with GCC (%d.%d.%d) ", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#else
    printf("(II) Code compiled with UNKWON compiler ");
#endif
    printf("the %s at %s\n", __DATE__, __TIME__);
    printf("(II)\n");
}

int main(int argc, char* argv[])
{

    header();

    int nRounds = 1;

    auto start_i_ref = std::chrono::system_clock::now();
    for(int32_t loop = 0; loop < nRounds; loop += 1)
    {
        hello();
    }
    auto stop_i_ref = std::chrono::system_clock::now();

    const uint64_t time_ref = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_i_ref - start_i_ref).count();
    printf("Number of Rounds [%8d] | Average [%8d ns/exec]  |  Average [%1.3f ns/round]\n", (int32_t)nRounds, (int32_t)time_ref, (time_ref/(float)nRounds));

    return 0;
}
    