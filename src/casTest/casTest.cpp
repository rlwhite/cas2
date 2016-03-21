#include <iostream>
#include <memory>
using namespace std;

#define printResult(err) cout <<                                 \
                                 (0 == err ? "All tests PASSED": \
                                  "One or more tests FAILED") << endl

struct Command
{
    virtual ~Command()
    {}

    virtual bool exec() = 0;
};

struct TestCommand : Command
{
    bool exec()
    {
        return true;
    }
};

Command* createCommand(int argc, const char* const argv[])
{
    return new TestCommand();
}

int main(int argc, const char* const argv[])
{
    int err(0);
    std::auto_ptr<Command> cmd(createCommand(argc, argv));

    if(!cmd->exec())
        ++err;

    printResult(err);

    return err;
}
