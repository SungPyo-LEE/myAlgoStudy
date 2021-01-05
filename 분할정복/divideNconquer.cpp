#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

// 1���� n������ ���� ���ϴ� ���(feat. �ݺ���)
int sum(int n)
{
    int ret = 0;
    for (int i =0; i<=n; ++i)
        ret += i;
    return ret;
}

// 1���� n������ ���� ���ϴ� ����� ���
int recursiveSum(int n)
{
    if(n == 1) return 1; //�������
    return n + recursiveSum(n-1);
}

//1���� n������ ���� ���ϴ� ���� ���� �˰���
int fastSum(int n)
{
    // ���� ���
    if(n==1) return 1;
    if(n % 2 == 1) return fastSum(n-1) + n;
    return 2*fastSum(n/2) + (n/2)*(n/2);
}
double getProcessTime(time_t start, time_t end)
{
    return (double)(end - start);
}

int main()
{
    time_t start, end;
    double res_time;

    start = time(NULL);
    int answer = fastSum(50000);
    end = time(NULL);
    res_time = getProcessTime(start, end);
    cout <<"Process Time "<<res_time<<"... Answer is " <<answer << endl;

    start = time(NULL);
    answer = sum(50000);
    end = time(NULL);
    res_time = getProcessTime(start, end);
    cout <<"Process Time "<<res_time<<"... Answer is " <<answer << endl;

    start = time(NULL);
    answer = recursiveSum(50000);
    end = time(NULL);
    res_time = getProcessTime(start, end);
    cout <<"Process Time "<<res_time<<"... Answer is " <<answer << endl;

    return 0;
}
