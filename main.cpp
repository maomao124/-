#include<iostream>
#include<stdio.h>
#include<string.h>
#include <Windows.h>
#include<time.h>
#include <graphics.h>
#include <conio.h>
#include<algorithm>
#include <random>
//vs2019自定义控制台代码模板 by mao
//作者QQ1296193245
using namespace std;

#pragma intrinsic(__rdtsc)
unsigned __int64 t1, t2, t3;
double run_time;                                                   //微秒级算法时间计时器
LARGE_INTEGER time_start;	                                //开始时间
LARGE_INTEGER time_over;	                                //结束时间
double dqFreq;		                                               //计时器频率
LARGE_INTEGER f;	                                               //计时器频率

inline void runstart()
{
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	t1 = __rdtsc();
	QueryPerformanceCounter(&time_start);	       //计时开始
}

inline void runend()
{
	QueryPerformanceCounter(&time_over);	        //计时结束
	run_time = 1000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	t2 = __rdtsc();
	t3 = t2 - t1;
	if (t3 < 10000)
	{
		cout << "CPU脉冲数：" << (t3) << endl;
	}
	else if (t3 < 100000000 && t3 >= 10000)
	{
		double tt = t3;
		cout << "CPU脉冲数：" << (tt) / 10000 << "万" << endl;
	}
	else if (t3 > 100000000000)
	{
		t3 = t3 / 10000000;
		double tt = t3;
		cout << "CPU脉冲数：" << (tt) / 10 << "亿" << endl;
	}
	else
	{
		t3 = t3 / 10000;
		double tt = t3;
		cout << "CPU脉冲数：" << (tt) / 10000 << "亿" << endl;
	}
	if (run_time > 10000)
	{
		cout << "算法运行时间：" << run_time / 1000 << "秒" << endl;
	}
	else if (run_time < 1)
	{
		cout << "算法运行时间：" << run_time * 1000 << "微秒" << endl;
	}
	else
	{
		cout << "算法运行时间：" << run_time << "毫秒" << endl;
	}
}

/*
void FpsTime(const time_t* t0, time_t* t1, const time_t* t2)// 图形界面计算显示FPS和运行时间
{
	if (!t0 || !t1 || !t2)
		return;
	static int FPS = 0;
	static int fps = 0;
	static wstring fpsTime;

	if (*t2 - *t1 == 1)
	{
		FPS = ++fps;
	}

	fpsTime = L"FPS: ";
	fpsTime += to_wstring(FPS);
	fpsTime += L" 运行时间: ";
	fpsTime += to_wstring(*t2 - *t0);
	fpsTime += L"s";
	settextcolor(LIGHTMAGENTA);
	outtextxy(0, 0, fpsTime.c_str());

	if (*t2 - *t1 == 1)
	{
		fps = 0;
		*t1 = time(nullptr);
	}
	else
	{
		fps++;
	}
}
*/
bool cmp(const int a, const int b)
{
	return a > b;
}
//**************************************************************



//**************************************************************

int main()
{
	// sort(data, data + 5, cmp);                     //排序算法 降序

	/*
	constexpr int MIN = 1;                            //随机数
	constexpr int MAX = 100;
	constexpr int numm = 10;
	 random_device rd;
	default_random_engine eng(rd());
	uniform_int_distribution<int> distr(MIN, MAX);

	for (int n = 0; n < numm; ++n)
	{
		cout << distr(eng) << ",";
	}
	*/
	/*
	initgraph(1600, 900);
	setbkcolor(WHITE);
	cleardevice();
	*/

	
	//***********************************************************
	int n, i;
	int s;
	cout << "设置时间，单位是秒,支持分钟和秒的组合输入，例如3分钟43秒，应输入3.43" << endl;
	cout << "请输入：";
	float x;
	cin >> x;
	if ((int)x == x)
	{

		n = x;
		cout << n << "秒" << endl;
	}
	else
	{

		int c = (int)x * 60;
		float d = x - (int)x;
		d = d * 100;
		d = d + 0.005;
		unsigned  int e = d;
		if (e >= 60)
		{
			cout << "小数部分输入错误" << endl;
			system("pause");
			exit(0);
			
		}
		cout << (int)x << "分钟" << e << "秒" << endl;
		n = c + e;
		cout << "共计" << n << "秒" << endl;
	}
		cout << "1.定时关机    2.定时休眠    3.定时睡眠" << endl;
		cout << "请选择：";
		cin >> i;
		if (n<=0)
		{
			cout << "时间输入错误" << endl;
				return 0;
		}
		if (i>3||i<1)
		{
			cout << "输入错误" << endl;
			return 0;
		}

		if (i==1)
		{
			for (int b=n;b>1;b--)
			{
				system("CLS");
				s = b / 60;
				if (b <= 10)
				{
					cout << b << "秒后,（" << s << "分钟后）关机，关闭程序可取消关机倒计时\a" << endl;
				}
				else
				{
					cout << b << "秒后,（" << s << "分钟后）关机，关闭程序可取消关机倒计时" << endl;
				}
				Sleep(995);
			}
			system("shutdown -s -t 1");
		}

		if (i == 2)
		{
			for (int c = n;c > 0;c--)
			{
				system("CLS");
				s = c / 60;
				if (c <= 10)
				{
					cout << c << "秒后,（" << s << "分钟后）休眠，关闭程序可取消休眠倒计时\a" << endl;
				}
				else
				{
					cout << c << "秒后,（" << s << "分钟后）休眠，关闭程序可取消休眠倒计时" << endl;
				}
				Sleep(995);
			}
			system("shutdown -h");
		}
		if (i == 3)
		{
			for (int d = n;d > 0;d--)
			{
				system("CLS");
				s = d / 60;
				if (d <= 10)
				{
					cout << d << "秒后,（" << s << "分钟后）睡眠，关闭程序可取消睡眠倒计时\a" << endl;
				}
				else
				{
					cout << d << "秒后,（" << s << "分钟后）睡眠，关闭程序可取消睡眠倒计时" << endl;
				}
				cout << "注意：如果你的 Windows 10 激活了休眠功能，执行此命令会直接进入休眠而非睡眠模式。";
				Sleep(995);
			}
			system("powercfg -h off");
			system("rundll32.exe powrprof.dll,SetSuspendState 0,1,0");
			system("powercfg -h on");
		}
	//***********************************************************
	

	
	//closegraph();
	// system("pause");
	//Sleep(10000);
	return 0;
}
