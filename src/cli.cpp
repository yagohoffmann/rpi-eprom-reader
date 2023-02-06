#include "cli.hpp"
#include "hal_gpio.hpp"

#include <iostream>
#include <unistd.h>

/**************************************************************************************************/
RpiCli::RpiCli(std::string fw_version){

    // Prints welcome banner with firmware version
    std::cout << "********************************************"                << std::endl;
    std::cout << "*        Welcome to rpi eprom reader       *"                << std::endl;
    std::cout << "*        Version: " << fw_version << "                    *" << std::endl;
    std::cout << "********************************************"                << std::endl;
}

/**************************************************************************************************/
int RpiCli::StartCli(){
    std::string input = "";
    int rv = EXIT_SUCCESS;

    HalGpio gpio;

    while (input != "exit")
    {
        Commands input_command;
        input = "";
        std::cout << "# ";
        std::getline(std::cin, input);

        if(input.empty()){
            continue;
        }

        auto it = cli_commands.find(input);
        if(it != cli_commands.end()){
            input_command = it->second;
            switch (input_command)
            {
            case SHOW_CHIP:
                std::cout << "Selected chip is 24C256" << std::endl;
                break;
            case TURN_OFF:
                std::cout << "Turning pin 14 off" << std::endl;
                gpio.SetValue(1,0);
                break;
            case TURN_ON:
                std::cout << "Turning pin 14 on" << std::endl;
                gpio.SetValue(1,1);
                break;
            case EXIT:
                std::cout << "Exiting application..." << std::endl;
            default:
                break;
            }
        } else{
            std::cout << "Command not found!" << std::endl;
        }
    }

    return rv;
}
/**************************************************************************************************/