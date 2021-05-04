#include "SoundPlayer.hpp"

SoundPlayer::SoundPlayer()
    : _soundBuffers(static_cast<size_t>(ID::Count))
{
    const std::vector<std::string> filenames {
        "gunshot.ogg",
    };
    for (int i { 0 }; i < _soundBuffers.size(); ++i)
        if (!_soundBuffers[i].loadFromFile("../sounds/" + filenames[i]))
            throw std::runtime_error("SoundPlayer: " + filenames[i]);
}

void SoundPlayer::play(ID id)
{
    _sounds.push_back(sf::Sound { _soundBuffers[static_cast<size_t>(id)] });
    _sounds.back().setVolume(30);
    _sounds.back().play();
}

void SoundPlayer::cleanUp()
{
    _sounds.remove_if([](auto& sound){ return sound.getStatus() == sf::Sound::Stopped; });
}
