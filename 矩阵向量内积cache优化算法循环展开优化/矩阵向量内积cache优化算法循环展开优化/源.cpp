#include<iostream>
#include<Windows.h>
using namespace std;
class TimerCounter
{
public:
    TimerCounter(void);//构造函数
    ~TimerCounter(void);//析构函数
private:
    LARGE_INTEGER startCount;//记录开始时间

    LARGE_INTEGER endCount;//记录结束时间

    LARGE_INTEGER freq;//本机CPU时钟频率
public:
    double dbTime;//程序运行的时间保存在这里

public:
    void Start();//被测程序开始点处开始计时
    void Stop();//被测程序结束点处结束计时
};
TimerCounter::TimerCounter(void)
{
    QueryPerformanceFrequency(&freq);//获取主机CPU时钟频率
}
TimerCounter::~TimerCounter(void)
{
}
void TimerCounter::Start()
{
    QueryPerformanceCounter(&startCount);//开始计时
}
void TimerCounter::Stop()
{
    QueryPerformanceCounter(&endCount);//停止计时

    dbTime = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)freq.QuadPart;//获取时间差

}
#define n 10000
int a[n][n];
int b[n];
int c[n] = { 0 };
int main() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = i + j;
            b[i] = i + j;
        }
    }
    TimerCounter tc;
    tc.Start();
    for (int j = 0; j < n-4; j+=4) {
        for (int i = 0; i < n; i++) {
            c[i] += a[j][i] * b[j];
            c[i] += a[j + 1][i] * b[j + 1];
            c[i] += a[j + 2][i] * b[j + 2];
            c[i] += a[j + 3][i] * b[j + 3];
        }
    }
    tc.Stop();
    /*for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }*/
    cout << endl << tc.dbTime;
    return 0;
}