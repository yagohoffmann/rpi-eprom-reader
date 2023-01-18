#ifndef RPI_EPROM_CLI_H_
#define RPI_EPROM_CLI_H_

#include <string>
#include <map>

enum Commands {
    EXIT,
    SHOW_CHIP,
    SET_CHIP,
    WRITE,
    READ,
    ERASE
};

class RpiCli{

    public:

    RpiCli(std::string fw_version);

    ~RpiCli();

    int StartCli();

    private:

    std::map<std::string, Commands> cli_commands = {{"exit", EXIT},
                                                    {"show chip", SHOW_CHIP},
                                                    {"set chip", SET_CHIP}};
};

#endif // RPI_EPROM_CLI_H_