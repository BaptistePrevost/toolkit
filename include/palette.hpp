#pragma once

#include <SFML/Graphics/Color.hpp>

namespace Colors {

    // ───────────────
    // Couleurs primaires
    // ───────────────
    constexpr sf::Color BLUE        {  15, 163, 177 };
    constexpr sf::Color RED         { 220,  53,  69 };
    constexpr sf::Color YELLOW      { 255, 193,   7 };

    // ───────────────
    // Couleurs secondaires
    // ───────────────
    constexpr sf::Color GREEN       {  40, 167,  69 };
    constexpr sf::Color ORANGE      { 255, 155,  66 };
    constexpr sf::Color PURPLE      { 108,  92, 231 };
    constexpr sf::Color PINK        { 232,  67, 147 };

    // ───────────────
    // Tons naturels / chauds
    // ───────────────
    constexpr sf::Color SAND        { 237, 222, 164 };
    constexpr sf::Color OCHRE       { 255, 155,  66 };
    constexpr sf::Color BROWN       { 150, 111,  51 };
    constexpr sf::Color PLUM        { 247, 160, 114 };

    // ───────────────
    // Tons froids
    // ───────────────
    constexpr sf::Color TEAL        {  32, 201, 151 };
    constexpr sf::Color CYAN        {  23, 162, 184 };
    constexpr sf::Color NAVY        {  20,  33,  61 };
    constexpr sf::Color DEEP_BLUE   {  0,   21,  36 }; //https://coolors.co/001524-15616d-ffecd1-ff7d00-78290f

    // ───────────────
    // Couleurs neutres
    // ───────────────
    constexpr sf::Color WHITE       { 255, 255, 255 };
    constexpr sf::Color LIGHT_GRAY  { 217, 229, 214 };
    constexpr sf::Color GRAY        { 160, 160, 160 };
    constexpr sf::Color DARK_GRAY   {  80,  80,  80 };
    constexpr sf::Color BLACK       {  20,  20,  20 };

    // ───────────────
    // États UI / feedback
    // ───────────────
    constexpr sf::Color SUCCESS     {  46, 204, 113 };
    constexpr sf::Color WARNING     { 241, 196,  15 };
    constexpr sf::Color ERROR       { 231,  76,  60 };
    constexpr sf::Color INFO        {  52, 152, 219 };

    // ───────────────
    // Transparences utiles
    // ───────────────
    constexpr sf::Color OVERLAY     {   0,   0,   0, 150 };
    constexpr sf::Color SHADOW      {   0,   0,   0,  80 };
    constexpr sf::Color HIGHLIGHT   { 255, 255, 255, 120 };
};