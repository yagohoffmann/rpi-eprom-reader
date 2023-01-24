#ifndef RPI_EPROM_HAL_GPIO_
#define RPI_EPROM_HAL_GPIO_

#include "gpiod.hpp"

class HalGpio{
    public:
    HalGpio();

    ~HalGpio();

    void SetState(int8_t pin, bool state);

    private:
    gpiod::line_bulk lines;
    gpiod::chip *gpio_chip = new gpiod::chip();

};

#endif //RPI_EPROM_HAL_GPIO_