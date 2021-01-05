#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

// 1부터 n까지의 합을 구하는 방법(feat. 반복문)
int sum(int n)
{
    int ret = 0;
    for (int i =0; i<=n; ++i)
        ret += i;
    return ret;
}

// 1부터 n까지의 합을 구하는 재귀적 방법
int recursiveSum(int n)
{
    if(n == 1) return 1; //기저사례
    return n + recursiveSum(n-1);
}

//1부터 n까지의 합을 구하는 분할 정복 알고리즘
int fastSum(int n)
{
    // 기저 사례
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
