#ifndef __AUDIO_H__
#define __AUDIO_H__

#include"SimpleAudioEngine.h"
using namespace CocosDenshion;

class Audio
{
public:
	Audio();
	virtual ~Audio();
	bool isPlayBackGroundMusic() { return isPlay; }
	void getBackGroundMusic();
	void stopBackGroundMusic();

private:
	SimpleAudioEngine *_audio;
	bool isPlay;
};



#endif // !__AUDIO_H__

