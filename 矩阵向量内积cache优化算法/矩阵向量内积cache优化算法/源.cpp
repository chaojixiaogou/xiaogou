#include<iostream>
#include<Windows.h>
using namespace std;
class TimerCounter
{
public:
    TimerCounter(void);//���캯��
    ~TimerCounter(void);//��������
private:
    LARGE_INTEGER startCount;//��¼��ʼʱ��

    LARGE_INTEGER endCount;//��¼����ʱ��

    LARGE_INTEGER freq;//����CPUʱ��Ƶ��
public:
    double dbTime;//�������е�ʱ�䱣��������

public:
    void Start();//�������ʼ�㴦��ʼ��ʱ
    void Stop();//�����������㴦������ʱ
};
TimerCounter::TimerCounter(void)
{
    QueryPerformanceFrequency(&freq);//��ȡ����CPUʱ��Ƶ��
}
TimerCounter::~TimerCounter(void)
{
}
void TimerCounter::Start()
{
    QueryPerformanceCounter(&startCount);//��ʼ��ʱ
}
void TimerCounter::Stop()
{
    QueryPerformanceCounter(&endCount);//ֹͣ��ʱ

    dbTime = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)freq.QuadPart;//��ȡʱ���

}
#define n 10
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
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            c[i] += a[j][i] * b[j];
        }
    }
    tc.Stop();
    /*for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }*/
    cout << endl << tc.dbTime;
    return 0;
}