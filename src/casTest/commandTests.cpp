#include "commandTests.h"

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
