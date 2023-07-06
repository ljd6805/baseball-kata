#include <stdexcept>
using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& question)
		: question(question)
	{
	}

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

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalAgument(guessNumber);

		if(guessNumber == question)
		{
			return { true, 3, 0 };
		}

		return { false, 0, 0 };
	}

private:
	string question;
};
