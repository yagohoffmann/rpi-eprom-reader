#include <iostream>

#include <gpiod.h>
#include <error.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct gpiod_chip *chip;
struct gpiod_line_request_config config;
struct gpiod_line_bulk lines;

int main(){
    std::cout << "Hello World!" << std::endl;

    unsigned int offsets[1];

    int values[1];
    int err;

    chip = gpiod_chip_open("/dev/gpiochip0");
    if(!chip)
    {
      perror("gpiod_chip_open");
    }

    // set pin 21 to 1 (logic high)
    offsets[0] = 14;
    values[0] = 0;

    err = gpiod_chip_get_lines(chip, offsets, 1, &lines);
    if(err)
    {
      perror("gpiod_chip_get_lines");
      return -1;
    }

    memset(&config, 0, sizeof(config));
    config.consumer = "blink";
    config.request_type = GPIOD_LINE_REQUEST_DIRECTION_OUTPUT;
    config.flags = 0;

    // get the bulk lines setting default value to 0
    err = gpiod_line_request_bulk(&lines, &config, values);
    if(err)
    {
      perror("gpiod_line_request_bulk");
      return -1;
    }

    // output value 1 to turn on the led
    values[0] = 1;
    err = gpiod_line_set_value_bulk(&lines, values);
    if(err)
    {
      perror("gpiod_line_set_value_bulk");
      return -1;
    }

    sleep(1);

    // output value 0 to turn off the led
    values[0] = 0;
    err = gpiod_line_set_value_bulk(&lines, values);
    if(err)
    {
      perror("gpiod_line_set_value_bulk");
      return -1;
    }

    gpiod_line_release_bulk(&lines);
    gpiod_chip_close(chip);

    return 0;
}
