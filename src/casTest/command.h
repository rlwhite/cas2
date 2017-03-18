#ifndef COMMAND_H
#define COMMAND_H

struct Command
{
    Command();

    virtual ~Command();

    virtual int exec() = 0;
};

#endif //COMMAND_H
