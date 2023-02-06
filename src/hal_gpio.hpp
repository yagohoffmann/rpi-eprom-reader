/*******************************************************************************/
/**
 * \file    hal_gpio.hpp
 *
 * \brief   Hardware abstration layer for gpio pins
 *
 */
/*******************************************************************************/

#ifndef RPI_EPROM_HAL_GPIO_
#define RPI_EPROM_HAL_GPIO_

#include "gpiod.h"

#define SOIC_8_PIN_NUMBER 5

/**
 * \brief HAL Gpio class
*/
class HalGpio{
   public:
    /**
    * \brief   Class constructor
    */
    HalGpio();

    /**
    * \brief   Class destructor
    */
    ~HalGpio();

    /**
    * \brief   Set socket pin value
    * \param   pin - socket to set
    * \param   value - logical value to be set on pin
    */
    void SetValue(int8_t pin, int value);

   private:
    struct gpiod_chip *chip;
    struct gpiod_line_request_config config;
    struct gpiod_line_bulk lines;
};

#endif //RPI_EPROM_HAL_GPIO_