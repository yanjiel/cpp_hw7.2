#include <iostream>
#include <cmath>
#include<future>
#include<functional>

using namespace std;

template<typename Func>
class my_packaged_task {
    
public:
    my_packaged_task(Func f) : fun(f) {}

    template<typename ...Arg>
    void operator()(Arg ...args) {
        jthread jt([=] {do_work(args...); });
    }

    template<typename ...Arg>
    void do_work(Arg ...args) {
        p.set_value(fun(args...));
    }
   
    auto get_future() {
        return p.get_future();
    }

private:
    Func* fun;
    using retT = typename decltype(function{*fun})::result_type;
    promise<retT> p;
    
};


double pow_of(int x, int y) { return pow(x, y); }


int main() {
	my_packaged_task<double(int, int)> task(pow_of);
    future<double> fd = task.get_future();
    task(2, 3);
    cout << "2 to the 3rd power is: " << fd.get();

}