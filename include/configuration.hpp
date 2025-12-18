#ifndef CONF_H
#define CONF_H

#include <SFML/Graphics.hpp>

/*********************************************
 * Configuration parameters for the simulation
 *********************************************/
namespace CONF {
    inline sf::Vector2u const WINDOW_SIZE = {1920, 1080}; //Fullscreen
    inline sf::Vector2f const WINDOW_SIZE_F = {1920.0f, 1080.0f}; //Fullscreen
    inline constexpr uint32_t const MAX_FRAMERATE = 120;
    inline constexpr float const DT = 1.0f / static_cast<float>(MAX_FRAMERATE);
    inline constexpr bool const USE_DT = true; //If true, use a constant step time for simualtion. Else, use real time 
    inline const sf::Color BG_COLOR = {29, 53, 87}; //DARK BLUE
}
#endif