#ifndef COMMANDRUNNER_H
#define COMMANDRUNNER_H

struct Command;

struct CommandRunner
{
    CommandRunner();

    int run(Command& cmd);
};

#endif //COMMANDRUNNER_H
