#pragma once

#include "Aircraft.hpp"
#include "Bullet.hpp"
#include "PendingChange.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

class Flagship : public Aircraft
{
public:
    Flagship(Context& context);
    void fireAction(std::vector<PendingChange>& changeQueue) override final;
    const sf::Vector2i& getNextStep() override;

private:
    sf::Texture& _bulletTexture;
    int _curStep = 0;
    
    //holder for context
    Context& _context;
};
