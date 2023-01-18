#include <iostream>
#include <gpiod.h>
#include <error.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include "cli.hpp"

void signal_callback_handler(int signum) {
    std::cout << std::endl;
    std::cout << "Closing after SIGINT" << std::endl;

    // Terminate program
    exit(signum);
}

int main(){

    signal(SIGINT, signal_callback_handler);

    RpiCli *cli = new RpiCli("0.1.0");

    cli->StartCli();

    return 0;
}
