#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map <string, int> cyclics;
	cyclics["142857"] = 1;
	cyclics["0588235294117647"] = 1;
	cyclics["052631578947368421"] = 1;
	cyclics["0434782608695652173913"] = 1;
	cyclics["0344827586206896551724137931"] = 1;
	cyclics["0212765957446808510638297872340425531914893617"] = 1;
	cyclics["0169491525423728813559322033898305084745762711864406779661"] = 1;
	cyclics["016393442622950819672131147540983606557377049180327868852459"] = 1;

	string num;
	while (cin >> num)
	{
		if (cyclics[num])
			cout << num << " is cyclic" << endl;
		else
			cout << num << " is not cyclic" << endl;
	}

	return 0;
}
