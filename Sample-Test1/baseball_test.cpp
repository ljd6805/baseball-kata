#include "pch.h"
#include "../Project6/baseball.cpp"

class BaseballFixture : public testing::Test
{
public:
	Baseball game;
	void assertIllegalArgument(string gussNumber)
	{
		try
		{
			game.guess(gussNumber);
			FAIL();
		}
		catch (exception e)
		{
			//pass
		}
	}
};


TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

