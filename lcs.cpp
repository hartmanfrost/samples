#include "stdafx.h"
#include <fstream>

using namespace std;

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	short n(0), m(0);
	ifs >> n;
	short* a = new short[n];
	for (short i(0); i < n; ++i) {
		ifs >> a[i];
	}
	ifs >> m;
	short* b = new short[m];
	for (short i(0); i < m; ++i) {
		ifs >> b[i];
	}
	short** d = new short*[n + 1];
	for (short i(0); i < n + 1; ++i) {
		d[i] = new short[m + 1];
		d[i][0] = 0;
	}
	for (short i(1); i < m + 1; ++i) {
		d[0][i] = 0;
	}
	for (short i(1); i < n + 1; ++i) {
		for (short j(1); j < m + 1; ++j) {
			d[i][j] = (d[i - 1][j] > d[i][j - 1]) ? d[i - 1][j] : d[i][j - 1];
			if (a[i - 1] == b[j - 1])	d[i][j]++;
		}
	}
	ofs << d[n][m];
	ofs.close();
	delete[] a;
	delete[] b;
	for (int i(0); i < n + 1; ++i)	delete[] d[i];
	return 0;
}
