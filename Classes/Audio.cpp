#include"Audio.h"

Audio::Audio()
{
	_audio = CocosDenshion::SimpleAudioEngine::getInstance();

}

Audio::~Audio()
{
}


void Audio::getBackGroundMusic()
{
	_audio->playBackgroundMusic("backMusic.mp3",true);
	isPlay = true;
}

void Audio::stopBackGroundMusic()
{
	_audio->pauseBackgroundMusic();
	isPlay = false;
}