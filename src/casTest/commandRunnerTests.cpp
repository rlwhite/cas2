#include "commandTests.h"

#include "command.h"
#include "commandRunner.h"

struct DoNothingCommand : Command
{
    DoNothingCommand(int retVal = 0)
	: execd_(false),
	  retVal_(retVal)
    {}

    int exec()
    {
	execd_ = true;
	return 0;
    }

    bool executed()
    {
	return execd_;
    }

private:
    bool execd_;
    int retVal_;
};

CommandRunnerExecutesDoNothingCommand::CommandRunnerExecutesDoNothingCommand()
    : TestCase()
{
    setName("CommandRunnerExecutesDoNothingCommand");
}

void CommandRunnerExecutesDoNothingCommand::run()
{
    DoNothingCommand cmd;

    CommandRunner().run(cmd);

    EXPECT_TRUE(cmd.executed());
}

