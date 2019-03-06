#include <iostream>
#include <CL/cl.hpp>
#include <vector>

//device - Graphics card
//host   - Computer processor

int main()
{
    //checking default platform
    std::vector<cl::Platform> all_Platforms;
    cl::Platform::get(&all_Platforms);
    if (all_Platforms.size() == 0)
    {
        std::cout << " No platforms found. Check OpenCL installation!\n";
        exit(1);
    }
    cl::Platform default_platform = all_Platforms[0];
    std::cout << "Using platform: " << default_platform.getInfo<CL_PLATFORM_NAME>() << "\n";

    //get default device of the default platform
    std::vector<cl::Device> all_devices;
    default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
    if (all_devices.size() == 0)
    {
        std::cout << " No devices found. Check OpenCL installation!\n";
        exit(1);
    }
    cl::Device default_device = all_devices[0];
    std::cout << "Using device: " << default_device.getInfo<CL_DEVICE_NAME>() << "\n";

    //this is something like a runtime link (or maybe imagine as a .out of CL which is used by main)
    cl::Context context({default_device});

    //a place to store the source code of the GPU program
    cl::Program::Sources sources;

    //source code
    std::string kernel_code =
        "   void kernel simple_add(global const int* A, global const int* B, global int* C){       "
        "       C[get_global_id(0)]=A[get_global_id(0)]+B[get_global_id(0)];                 "
        "   } ";

    sources.push_back({kernel_code.c_str(), kernel_code.length()});

    //storing and building the program
    cl::Program program(context, sources);
    if (program.build({default_device}) != CL_SUCCESS)
    {
        std::cout << " Error building: " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(default_device) << "\n";
        exit(1);
    }

    // create buffers on the device-Graphics card
    cl::Buffer buffer_A(context, CL_MEM_READ_WRITE, sizeof(int) * 10);
    cl::Buffer buffer_B(context, CL_MEM_READ_WRITE, sizeof(int) * 10);
    cl::Buffer buffer_C(context, CL_MEM_READ_WRITE, sizeof(int) * 10);

    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int B[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0};

    //create queue to which we will push commands for the device.
    cl::CommandQueue queue(context, default_device);

    //write arrays A and B to the device
    queue.enqueueWriteBuffer(buffer_A, CL_TRUE, 0, sizeof(int) * 10, A);
    queue.enqueueWriteBuffer(buffer_B, CL_TRUE, 0, sizeof(int) * 10, B);

    //creating a keranl function which can be called from the host

    cl::Kernel simple_add(program, "simple_add");
    simple_add.setArg(0, buffer_A);
    simple_add.setArg(1, buffer_B);
    simple_add.setArg(2, buffer_C);
    queue.enqueueNDRangeKernel(simple_add,cl::NullRange, cl::NDRange(10), cl::NullRange);

    int C[10];
    //read result C from the device to array C
    queue.enqueueReadBuffer(buffer_C,CL_TRUE,0,sizeof(int)*10,C);

    std::cout<<" result: \n";
    for(int i=0;i<10;i++)
    {
        std::cout<<C[i]<<" ";
    }

    std::cout<<std::endl;return 0;
}