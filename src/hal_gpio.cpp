#include "hal_gpio.hpp"
#include <map>
#include <vector>

using namespace gpiod;
using namespace std;


map<unsigned int, unsigned int> socket_pin_map = {{1,14}};

/**************************************************************************************************/
HalGpio::HalGpio(){
    vector<unsigned int> offsets = {};

    gpio_chip->open("/dev/gpiochip0");
    for(const auto &rpi_pin : socket_pin_map)
    {
        offsets.push_back(rpi_pin.second);
    }
    lines = gpio_chip->get_lines(offsets);
    lines.request({"rpi-eeprom-reader", gpiod::line_request::DIRECTION_OUTPUT,0}, {0});
}

HalGpio::~HalGpio(){
    lines.release();
}

void HalGpio::SetState(int8_t pin, bool state){

}