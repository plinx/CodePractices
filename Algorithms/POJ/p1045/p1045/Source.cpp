#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	float Vs, R, C;
	int num;
	float w;

	cin >> Vs >> R >> C >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> w;
		cout << fixed << setprecision(3) <<  Vs * R * C * w * sqrt(1 / (R*R * C*C * w*w + 1)) << endl;
	}

	return 0;
}

/*
V1 = Vs*cos(wt), V2 = Vr*cos(wt+q)
V2 = i*R = R*C* d(V1-V2)/dt
=> Vr*cos(wt+q) = R*C* d(V1-V2)/dt
d(cos(wt))/dt = -w * sin(wt)
=> Vr*cos(wt+q) = R*C*w (Vr*sin(wt+q) - Vs*sin(wt))
let wt+q = 0 (wt = -q)
=> Vr = R*C*w*Vs*sin(q)
let wt = 0
=> Vr*cos(q) = R*C*w*Vr*sin(q)
cot(q) = R*C*w
cos^2(q)/sin^2(q) = (R*C*w)^2
cos^2(q)/sin^2(q) + 1 = (R*C*w)^2 + 1
=> 1/sin^2(q) = (R*C*w)^2 + 1
=> sin(q) = sqrt(1/((R*C*w)^2 +1 ))
=> Vr = R*C*w*Vs* sqrt(1/((R*C*w)^2 + 1))
*/
