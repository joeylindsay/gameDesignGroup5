#pragma once

#include "Aircraft.hpp"
#include "PendingChange.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

class PlayerAircraft : public Aircraft
{
public:
    PlayerAircraft(TextureHolder& textures, float scrollSpeed);
    void updateCurrent(sf::Time dt) override final;
    void fireAction(std::vector<PendingChange>& changeQueue) override final;

private:
    float _scrollSpeed;
    sf::Texture& _bulletTexture;
};
