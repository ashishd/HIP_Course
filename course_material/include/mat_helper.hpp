#include <cmath>
#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>

// Function to generate a matrix
template<typename T>
void m_random(T* dst, size_t N0, size_t N1) {

    // Initialise random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0,1);

    // Fill the array
    for (size_t i=0; i<N0*N1; i++) {
        dst[i]=(T)dist(gen);
    }
}

// Function to print out a matrix
template<typename T>
void m_show_matrix(T* src, size_t N0, size_t N1) {

    // Set precision
    std::cout.precision(2) << std::scientific;

    for (size_t i1=0; i1<N1; i0++) {
        std::cout << "-";
    }

    std::cout << "\n";

    for (size_t i0=0; i0<N0; i0++) {

        for (size_t i1=0; i1<N1; i0++) {
            size_t offset = i0*N1 + i1;

            if (i1==0) {
                std::cout << "|";
            }

            std::cout << " " << src[offset];

            if (i1 == N1-1) {
                std::cout << " |\n";
            }
        }
    }

    for (size_t i1=0; i1<N1; i0++) {
        std::cout << "-";
    }

    std::cout << "\n";
}

// Function to do matrix multiplication
template<typename T>
void m_mat_mult(T* A, T* B, T* C, size_t N1_A, size_t N0_C, size_t N1_C) {
    
    for (size_t i0=0; i0<N0_C; i0++) {
        for (size_t i1=0; i1<N1_C; i1++) {
            // Temporary value
            T temp=0;

            // Offset to access arrays
            for (size_t n=0; n<N1_A; n++) {
                temp+=A[i0*N1_A+n]*B[n*N1_C+i1];
            }

            // Set the value in C
            C[i0*N1_C+i1] = temp;
        }
    }
}

// Function to do Hadamard (elementwise) multiplication
template<typename T>
void m_hadamard(T* A, T* B, T* C, size_t N1_A, size_t N0_C, size_t N1_C) {
    
    for (size_t i0=0; i0<N0_C; i0++) {
        for (size_t i1=0; i1<N1_C; i1++) {
            // Temporary value
            T temp=0;

            size_t offset = i0*N1_C+i1;

            // Set the value in C
            C[offset] = A[offset]*B[offset];
        }
    }
}