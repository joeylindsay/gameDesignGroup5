#pragma once

#include "Aircraft.hpp"
#include "PendingChange.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

class Bogey : public Aircraft
{
public:
    Bogey(Context& context);
    void fireAction(std::vector<PendingChange>& changeQueue) override final;

private:
    sf::Texture& _bulletTexture;
};
