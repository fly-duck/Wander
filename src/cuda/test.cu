#include <__clang_cuda_builtin_vars.h>
#include <stdio.h>
#include <iostream>

struct Test{
    int a;
    int b;
};


__global__ void HelloGPU(const Test& test){
    printf("thread %d , GPU output\n", threadIdx.x);
    //std::cout << test.a <<"\n";
}

int main(void)

{
    Test test;
    
    printf("hello cuda\n");

    HelloGPU<<<1,10>>>(test);
    cudaDeviceSynchronize();
    //cudaDeviceReset();
    return 0;
}
