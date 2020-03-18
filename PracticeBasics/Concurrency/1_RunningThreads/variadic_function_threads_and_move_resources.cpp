#include <iostream>
#include <thread>
#include <string>

void printName(std::string name, int waitTime)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    std::cout << "Name (from Thread) = " << name << std::endl;
}

int main()
{
    std::string name1 = "MyThread1";
    std::string name2 = "MyThread2";

    // starting threads using value-copy and move semantics 
    std::thread t1(printName, name1, 50);
    std::thread t2(printName, std::move(name2), 100); 
    //Note:we just move resource of name2 to pass it in 'name' arg of  printName 
    //Thus, name2 

    // wait for threads before returning
    t1.join();
    t2.join();

    // print name from main
    std::cout << "Name (from Main) = " << name1 << std::endl;
    std::cout << "Name (from Main) = " << name2 << std::endl; // because the resource is moved , so we cant access to it any more, name2 is empty

    // ╰>  ./a.out
    // Name (from Thread) = MyThread1
    // Name (from Thread) = MyThread2
    // Name (from Main) = MyThread1
    // Name (from Main) = 

    return 0;
}