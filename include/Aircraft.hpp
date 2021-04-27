/// \file Aircraft.hpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Header file for the Aircraft class
/// \date 2021-04-02
#pragma once

#include "Command.hpp"
#include "PendingChange.hpp"
#include "SceneNode.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

/// Super class for all aircrafts.
class Aircraft : public SceneNode {
public:
    Aircraft(sf::Texture& texture, const sf::IntRect& sizeRect);
    /// Check if within fire interval. If so, issue fire command.
    void fire(std::vector<PendingChange>& changeQueue);
    /// Concrete fire commands.
    virtual void fireAction(std::vector<PendingChange>& changeQueue);
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override final;
    /// Returns the current HP value.
    int getHealth() const;
    void updateCurrent(sf::Time dt) override;
    void damage(int damagePt) override final;

protected:
    int _health { 100 };
    /// Time interval allowed between fire
    sf::Time _fireInterval { sf::seconds(0.2f) };
    /// Countdown time for time allowed before next fire
    sf::Time _fireCountdown { sf::seconds(0.0f) };
};
