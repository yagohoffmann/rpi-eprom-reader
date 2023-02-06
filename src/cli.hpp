/*******************************************************************************/
/**
 * \file    cli.hpp
 *
 * \brief   Command line interface
 *
 */
/*******************************************************************************/

#ifndef RPI_EPROM_CLI_H_
#define RPI_EPROM_CLI_H_

#include <string>
#include <map>

#define EXIT_CLI_ERROR -1

/**
 * \brief Cli commands enumeration
*/
enum Commands {
    EXIT,
    SHOW_CHIP,
    SET_CHIP,
    WRITE,
    READ,
    ERASE,
    TURN_ON,
    TURN_OFF
};

/**
 * class RpiCli
 */
class RpiCli{

   public:
    /**
     * \brief   Class constructor
     * \param   fw_version FW version to show on banner
     */
    RpiCli(std::string fw_version);

    /**
     * \brief   Class destructor
     */
    ~RpiCli();

    /**
     * \brief   Starts the command line interface
     * \return  EXIT_SUCCES if closed gracefully - EXIT_CLI_ERROR otherwise
     */
    int StartCli();

   private:
    /**
     * \brief Holds all suported commands by the command line interface in a key value map.
    */
    std::map<std::string, Commands> cli_commands = {{"exit", EXIT},
                                                    {"show chip", SHOW_CHIP},
                                                    {"set chip", SET_CHIP},
                                                    {"turn on", TURN_ON},
                                                    {"turn off", TURN_OFF}};
};

#endif // RPI_EPROM_CLI_H_