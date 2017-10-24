#include <iostream>
#include <sys/time.h>
#include <assert.h>
using namespace std;

timeval GetLocalTime(void)
{
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv,&tz);
    return tv;
}

int out=0;

int fib_vectfun(int cnt,int pfib[])
{
    assert(cnt > 0);
    if(pfib[cnt-1] != 0)
        return pfib[cnt-1];
    else
    {
        out = fib_vectfun(cnt-1,pfib) + fib_vectfun(cnt-2,pfib);
        pfib[cnt-1] = out;
        return out;
    }
}

int fib(int cnt)
{
    assert(cnt > 0);
    if(cnt == 1)return 1;
    else if(cnt == 2)return 1;
    else
    {
        out = fib(cnt-1) + fib(cnt-2);
        return out;
    }
}


int main()
{

    int fib_vect[1000]={0};
    fib_vect[0] = 1;
    fib_vect[1] = 1;

    timeval t1 = GetLocalTime();
    int i= 0;
    while(i++<10)
        cout<<fib_vectfun(i,fib_vect)<<endl;
    timeval t2 = GetLocalTime();
    cout<< "vect fun time spend:"<<(t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec - t1.tv_usec)<<" usecond"<<endl;



    t1 = GetLocalTime();
    i= 0;
    while(i++<10)
        cout<<fib(i)<<endl;
    t2 = GetLocalTime();
    cout<< "non vect fun time spend:"<<(t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec - t1.tv_usec)<<" usecond"<<endl;

    return 0;
}


