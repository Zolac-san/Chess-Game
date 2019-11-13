
#include <iostream>
#include <mutex>
#include <controller.h>
#include <sys/resource.h>

std::mutex mtx;

int main(int argc, char const *argv[])
{

    const rlim_t kStackSize = 32 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
	
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }


    IController* controller = new Controller();
    controller->start();



    return 0;
}
