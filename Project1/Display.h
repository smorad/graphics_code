#pragma once

#include <string>
#include <sdl2\SDL.h>

class Display {
public:
	Display(int width, int height, const std::string& title);
	void Update();
	virtual ~Display();
	bool isClosed();
	void Clear(float r, float g, float b, float a);
private:
	SDL_Window *m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};