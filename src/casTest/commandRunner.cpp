#include "commandRunner.h"
#include "command.h"

CommandRunner::CommandRunner()
{}

int CommandRunner::run(Command& cmd)
{
    return cmd.exec();
}
