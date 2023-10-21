/**
 * (C)Basel::Alhajri->MBH();
 */

#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <atomic>
#include <cmath>

#define PI 3.1415926535897

#ifdef _WIN32

#define ISWIN true

#else

#define ISWIN false

#endif


using namespace std;
using namespace this_thread;
using namespace chrono;

atomic<bool> con;

void input();
inline void clr();
void pil(int (*m)());

const int lam = 10;
bool s = false;

int main() {
	if(::s) {
		cout << "Press any key to start except power off key...";
		_getch();
		::s = true;
	}
	clr();
	con.store(false);
	pil(main);
}

void input() {
	_getch();
	con.store(true);
}

string wave(int i, int j, string c, string c1) {
	int lam = (floor(abs(sin(j*(PI/::lam)))*3));
	return (lam >= i%5) ? c1 : c;
}
int dv = 0, df = 0;
void init(int (*m)()) {
	cout << endl;
	dv = (dv-1) % ::lam;
	for (int i = 0, len = 20, w = 60, di = 1, j; i < len; di = i++ < len/2 - 1 ? i+2+sin(df++*PI/(::lam+1)) : len - i - sin(df++*PI/(::lam-1)), di = di*2, cout << "\033[0;100m") {
		for (j = 0; j < w; j++) {
			int arr[] = {j<di?101:40, j<di?101:107, j<di?101:42, 100};
			string c0 = to_string(arr[i/5]);
			string cn1 = ((i/5==0)?"100":to_string(arr[i/5-1]));
			string fc = "\033[1;"+c0+ "m";
			cout << wave(i, j + dv + PI/2, fc, "\033[1;"+cn1+"m");
			cout << ' ';
		}
		cout << endl;
		if (i == len -1) {
			cout << "\n\nPress any key to stop except power off...";
		}
	}
	cout << endl;
	while (!con.load()) {
		sleep_for(milliseconds(200));
		clr();
		init(m);
		return;
	}
	::s = true;
}

void pil(int (*m)()){
	thread t(input);
	//thread d(init, m);
	init(m);
	t.join();
	//con.store(true);
	//d.join();
	m();
}

inline void clr() {
	system(ISWIN ? "cls" : "clear");
}
