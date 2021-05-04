#pragma once

#include <SFML/Audio.hpp>
#include <list>

class SoundPlayer : private sf::NonCopyable
{
public:
    enum class ID {
        Gunshot,
        Count
    };
    SoundPlayer();
    void play(ID id);
    void cleanUp();

private:
    std::vector<sf::SoundBuffer> _soundBuffers;
    std::list<sf::Sound> _sounds;
};
