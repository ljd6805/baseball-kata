#include <stdexcept>
using namespace std;

class Baseball
{
public:
	void guess(const string& gussNumber)
	{
		if (gussNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for(char ch : gussNumber)
		{
			if(ch < '0' || ch > '9')
			{
				throw invalid_argument("Must be number.");
			}
		}

		if(gussNumber[0]==gussNumber[1]
			|| gussNumber[0] == gussNumber[2]
			|| gussNumber[1] == gussNumber[2])
		{
			throw invalid_argument("Must Not have the same number");
		}
	}
};
