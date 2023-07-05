#include <stdexcept>
using namespace std;

class Baseball
{
public:
	bool isDuplicateNumber(const string& gussNumber)
	{
		return gussNumber[0] == gussNumber[1]
			|| gussNumber[0] == gussNumber[2]
			|| gussNumber[1] == gussNumber[2];
	}

	void assertIllegalAgument(const string& gussNumber)
	{
		if (gussNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for(char ch : gussNumber)
		{
			if(ch >= '0' && ch <= '9')	continue;
			throw invalid_argument("Must be number.");
		}

		if(isDuplicateNumber(gussNumber))
		{
			throw invalid_argument("Must Not have the same number");
		}
	}

	void guess(const string& gussNumber)
	{
		assertIllegalAgument(gussNumber);
	}
};
