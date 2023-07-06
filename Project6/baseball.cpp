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

	int checkStrikes(const string& guessNumber)
	{
		int strikes = 0;
		for(int i=0;i<3;i++)
		{
			if(guessNumber[i]==question[i])
			{
				strikes++;
			}
		}

		return strikes;
	}

	int checkBalls(const string& guessNumber)
	{
		int balls = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((i!=j) && (guessNumber[i]==question[j]))
				{
					balls++;
				}
			}
		}

		return balls;
	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalAgument(guessNumber);
		GuessResult result = {false,0,0};
		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}

		result.strikes = checkStrikes(guessNumber);

		result.balls =  checkBalls(guessNumber);

		return result;
	}

private:
	string question;
};
