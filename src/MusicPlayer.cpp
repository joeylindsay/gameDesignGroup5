#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer()
    : _fileNames {
        "game.ogg",
        "menu.ogg"
    }
{
}

void MusicPlayer::play(ID id)
{
    const std::string fileName = _fileNames[static_cast<size_t>(id)];
    if (!_music.openFromFile("../sounds/" + fileName))
        throw std::runtime_error("MusicPlayer: Failed to load " + fileName);
    _music.setVolume(100);
    _music.setLoop(true);
    _music.play();
}

void MusicPlayer::stop()
{
    _music.stop();
}
