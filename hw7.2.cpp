#include <iostream>
#include <cmath>
#include<future>

using namespace std;

//template<typename Func, typename ...Arg>
//auto my_packaged_task(Func f, Arg ...args) {
//	promise<int> p;
//	future<int> f = p.get_future();
//
//	p.set_value(7);
//	return f;
//}

template<typename Func>
class my_packaged_task {
public:
    my_packaged_task() {}
    my_packaged_task(Func f): fun(f) {
        fv = p.get_future();
    }

    template<typename ...Arg>
    int operator()(Arg ...args) {
        

        
        return 1;
    }

private:
    Func* fun;
    promise<int> p;
    future<int> fv;
};

double pow_of(int x, int y) { return pow(x, y); }

void task_lambda()
{
    packaged_task<int(int, int)> task( [](int a, int b){return pow(a, b);} );
    future<int> result = task.get_future();
    task(2, 9);
    cout << "task_lambda:\t" << result.get() << '\n';
}

int main() {
	task_lambda();
	my_packaged_task<double(int, int)> task(pow_of);
    cout << task(1, 2);
}