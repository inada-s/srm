//--------------------------------
//this code contain some bugs...
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <complex>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define dump(x)  cout<<#x<<" = "<<(x)<<endl;
const double EPS = 1e-10;
const long double PI = acos(-1.0);
const int INF = 1<<30;

typedef complex<long double> CD;
typedef vector<CD> VCD;

struct FencingPenguinsEasy
{
	VCD pen,round;

	void make_pen(vector<int> x, vector<int> y)
	{
		pen.clear();
		const int n = x.size();
		rep(i,n)pen.push_back(CD(x[i],y[i]));
	}

	void make_round(int n, int r)
	{
		round.clear();
		const long double dr   = 2.0L*PI / n;
		const long double radi = r;
		rep(i,n)round.push_back(polar(radi,dr*i));
	}

	long double cross(CD a, CD b)
	{
		return a.real() * b.imag() - a.imag() * b.real();
	}

	long double calc_area(vector<int> idx)
	{
		sort(idx.begin(),idx.end());
		long double area = 0L;
		const int n = idx.size();
		rep(i,n-2)
		{
			CD ab = round[idx[i+1]] - round[idx[0]];
			CD ac = round[idx[i+2]] - round[idx[0]];
			area += abs(cross(ab, ac)) / 2.0L;
		}
		return area;
	}

	bool check_pos(int pos, int npos)
	{
		CD a = round[npos] - round[pos];
		bool ok = true;
		rep(j,pen.size())
		{
			CD b = pen[j] - round[pos];
			if(cross(a,b)<0.0)
			{
				ok = false;
				break;
			}
		}
		return ok;
	}

	int find_next_pos(int pos)
	{
		int ret = -1;
		const int n = round.size();
		rep(i,n-1)
		{
			int npos = (pos+i+1)%n;
			if(check_pos(pos, npos))
				ret = npos;
			else
				break;
		}
		return ret;
	}

	double calculateMinArea(int n, int r, vector <int> x, vector <int> y)
	{
		make_pen(x,y);
		make_round(n,r);

		int pos=0;
		rep(i,n)
		{
			pos = find_next_pos(pos);
			if(pos < 0)
				return -1;
		}

		long double min_area = r*r*PI;
		rep(i,n)
		{
			vector<int> idx;
			idx.push_back(i);
			int cur_pos = i;
			while(true)
			{
				cur_pos = find_next_pos(cur_pos);
				idx.push_back(cur_pos);
			  if(check_pos(cur_pos,i))break;
			}

			if(min_area > calc_area(idx))
			{
				cout << "-----" << endl;
				rep(k,idx.size())
				{
					dump(idx[k]);
				}
			}

			min_area = min(min_area, calc_area(idx));
		}

		return double(min_area);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {-1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 32.47595264191645; verify_case(0, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 30; int Arg1 = 5; int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = -1.0; verify_case(1, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 5; int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 25.0; verify_case(2, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arr2[] = {2,-2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 50.0; verify_case(3, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 5; int Arr2[] = {8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = -1.0; verify_case(4, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 7; int Arg1 = 10; int Arr2[] = {9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 29.436752637711805; verify_case(5, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 30; int Arg1 = 800; int Arr2[] = {8,2,100,120,52,67,19,-36}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-19,12,88,-22,53,66,-140,99}
; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 384778.74757953023; verify_case(6, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arg0 = 221; int Arg1 = 100000; int Arr2[] = {99999,-99999,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,99999,-99999}
; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = -1.0; verify_case(7, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_8() { int Arg0 = 221; int Arg1 = 100000; int Arr2[] = {9000,-9000,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,9000,-9000}
; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1.9732E10; verify_case(8, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	FencingPenguinsEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
