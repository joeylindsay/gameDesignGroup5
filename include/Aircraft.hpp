/// \file Aircraft.hpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Header file for the Aircraft class
/// \date 2021-04-02
#pragma once

#include "Command.hpp"
#include "PendingChange.hpp"
#include "SceneNode.hpp"
#include "TextureHolder.hpp"
#include "Context.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

/// Super class for all aircrafts.
class Aircraft : public SceneNode {
public:
    Aircraft(sf::Texture& texture, const sf::IntRect& sizeRect, Context& context);
    /// Check if within fire interval. If so, issue fire command.
    bool fire(std::vector<PendingChange>& changeQueue);
    /// Concrete fire commands.
    virtual void fireAction(std::vector<PendingChange>& changeQueue);
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override final;
    /// Returns the current HP value.
    int getHealth() const;
    void updateCurrent(sf::Time dt, bool timeStop) override;
    void damage(int damagePt) override final;
    virtual const sf::Vector2i& getNextStep();

protected:
    int _health { 100 };
    int count = 0;
    /// Time interval allowed between fire
    sf::Time _fireInterval { sf::seconds(0.2f) };
    /// Countdown time for time allowed before next fire
    sf::Time _fireCountdown { sf::seconds(0.0f) };
    // Enemy path
    std::vector<sf::Vector2i> _steps;
    int _curStep { 0 };
    //container to hold the reference to context
    Context& _context;
};
