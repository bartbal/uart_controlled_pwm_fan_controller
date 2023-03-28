/*
 * File: pwmFanControl.hpp
 * Project: atp humidity control
 * File Created: Monday, 27th March 2023 1:46:17 pm
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Tuesday, 28th March 2023 5:18:29 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#define FAN_PWM_PIN 2
#define FAN_TACH_PIN 27

class PwmFanControl{
private:
    
    /**
     * @brief 
     * This method is used for updating the pwm level on a wrap interrupt
     */
    static void on_pwm_wrap();
public:
    /**
     * @brief 
     * Initialize the pwm controller. 
     * @details
     * this method will configure the pwm fan 
     * controller and set all its interrupts
     */
    static void init();

    /**
     * @brief 
     * Thread safe way of retreiving the speed of the pwm fan
     * @return uint8_t 
     * the speed of the pwm fan in percentage
     */
    static uint8_t getSpeed();

    /**
     * @brief
     * Thread safe way of setting the speed of the pwm fan
     * @param newSpeed 
     * New speed in percentage. If higher then 100 will be set to 100
     */
    static void setSpeed(uint8_t newSpeed);
};
