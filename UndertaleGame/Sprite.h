#pragma once
#include "Texture.h"

class Sprite
{
public:
	Sprite(int framesPerPlayer[]);
	~Sprite();


	
private:
	int m_FramesPerPlayer;
	int m_width;
	int m_height;
	

};

