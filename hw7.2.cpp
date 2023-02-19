#include <iostream>
#include <cmath>
#include<future>
#include<functional>

using namespace std;


double pow_of(int x, int y) { return pow(x, y); }

void task_lambda()
{
    packaged_task<double(int, int)> task( [](int a, int b){return pow(a, b);} );
    future<double> result = task.get_future();
    task(2, 9);
    cout << "task_lambda:\t" << result.get() << '\n';
}

void func(std::promise<int>&& p) {
    p.set_value(10);
}


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
        double result = fun(args...);
        p.set_value(result);
    }
   
    future<double> get_future() {
        return p.get_future();
    }

private:
    Func* fun;
    //future<double> fv;
    promise<double> p;
    
};



int main() {
	//task_lambda();
	my_packaged_task<double(int, int)> task(pow_of);
    future<double> fd = task.get_future();
    task(2, 3);
    cout << fd.get();

}