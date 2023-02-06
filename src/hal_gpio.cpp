#include "hal_gpio.hpp"

#include <errno.h>
#include <map>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;


map<unsigned int, unsigned int> socket_pin_map = {{1,14}};

/**************************************************************************************************/
HalGpio::HalGpio(){

    unsigned int offsets[1];
    int values[1];

    chip = gpiod_chip_open("/dev/gpiochip0");
    if(!chip)
    {
        cout << "Error opening chip" << endl;
    }

    offsets[0] = 14;
    values[0] = 0;

    int err;
    err = gpiod_chip_get_lines(chip, offsets, 1, &lines);
    if(err)
    {
        cout << "Error getting lines" << endl;
    }

    memset(&config, 0, sizeof(config));
    config.consumer = "rpi-eprom-reader";
    config.request_type = GPIOD_LINE_REQUEST_DIRECTION_OUTPUT;
    config.flags = 0;

    err = gpiod_line_request_bulk(&lines, &config, values);
    if(err)
    {
      cout << "Error requesting lines" << endl;
    }

}

HalGpio::~HalGpio(){
    int values[1];
    int err;

    // output value 0 to turn off the led
    values[0] = 0;
    err = gpiod_line_set_value_bulk(&lines, values);
    gpiod_line_release_bulk(&lines);
    gpiod_chip_close(chip);
}

/**************************************************************************************************/
void HalGpio::SetValue(int8_t pin, int value){

    int values[1];
    int err;

    // output value 0 to turn off the led
    values[0] = value;
    err = gpiod_line_set_value_bulk(&lines, values);
    if(err)
    {
      cout << "Error setting value" << endl;
    }
}