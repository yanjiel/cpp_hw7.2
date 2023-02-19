//#include <iostream>
//#include <cmath>
//#include<future>
//#include<functional>
//
//using namespace std;
//
//
//double pow_of(int x, int y) { return pow(x, y); }
//
//void task_lambda()
//{
//    packaged_task<double(int, int)> task([](int a, int b) {return pow(a, b); });
//    future<double> result = task.get_future();
//    task(2, 9);
//    cout << "task_lambda:\t" << result.get() << '\n';
//}
//
//void func(std::promise<int>&& p) {
//    p.set_value(10);
//}
//
//
//int main() {
//    task_lambda();
//}