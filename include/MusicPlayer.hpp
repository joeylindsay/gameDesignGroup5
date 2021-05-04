#pragma once

#include <SFML/Audio.hpp>

class MusicPlayer : private sf::NonCopyable
{
public:
    enum class ID {
        Game,
        Menu
    };
    MusicPlayer();
    void play(ID id);
    void stop();

private:
    std::vector<std::string> _fileNames;
    sf::Music _music;
};
