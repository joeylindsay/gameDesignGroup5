#pragma once

#include "Aircraft.hpp"
#include "PendingChange.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

class Screamer : public Aircraft
{
public:
    Screamer(TextureHolder& textures);
    void fireAction(std::vector<PendingChange>& changeQueue) override final;

private:
    sf::Texture& _bulletTexture;
};
