#include "pch.h"
#include "../Project6/baseball.cpp"

class BaseballFixture : public testing::Test
{
public:
	Baseball game{"123"};
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

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);

}

TEST_F(BaseballFixture, ReturnSolvedResultIfTwoStrikeZeroBall) {
	GuessResult result = game.guess("193");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);

}

