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

	GuessResult checkStrikes(const string& guessNumber)
	{
		GuessResult result = { false, 0, 0 };
		for(int i=0;i<3;i++)
		{
			if(guessNumber[i]==question[i])
			{
				result.strikes++;
			}
		}

		return result;
	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalAgument(guessNumber);
		GuessResult result = {false,0,0};
		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}

		result = checkStrikes(guessNumber);

		return result;
	}

private:
	string question;
};
