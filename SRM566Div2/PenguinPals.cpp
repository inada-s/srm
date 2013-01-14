#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
#define rep(i,n) for(int i=0;i<n;++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

class PenguinPals {
public:
  int findMaximumMatching(string str) {
  int res=0;

	while(str.size()>1)
	{
		if(str == "BR" || str == "RB" )
		{
			break;
		}

		int a=0;
		int b=0;
		int len=str.size();

		rep(i,str.size())
		{
			//plus
			for(int j=1; j<str.size(); ++j)
			{
				int idx = (i+j)%str.size();
				if(str[i] == str[idx])
				{
					if(j<len)
					{
						len = j;
						a = i;
						b = idx;
					}
					break;
				}
			}
			//minus
			for(int j=1; j<str.size(); ++j)
			{
				int idx = i-j;
				if( idx < 0 )
				{
					idx += str.size();
				}

				if(str[i] == str[idx])
				{
					if(j<len)
					{
						len = j;
						a = i;
						b = idx;
					}
					break;
				}
			}
		}

		if( a+len == b )
		{
			str.erase(a,len+1);
		}
		else if( b+len == a )
		{
			str.erase(b,len+1);
		}
		else
		{
			int mi = min(a,b);
			int mx = max(a,b);

			str.erase(mx);
			str.erase(0,mi+1);
		}
		res ++;
	}

    return res;
  }
  
  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
