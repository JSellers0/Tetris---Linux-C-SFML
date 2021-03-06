/* Adapted from https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-2-the-first-state/124
 * 
 * Copyright (c) 2014 Daniel Mansfield under the MIT License (MIT)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 * THE SOFTWARE.
 */ 
 
#ifndef GAME_STATE_PAUSE_HPP
#define GAME_STATE_PAUSE_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "game_state.hpp"
#include "gui.hpp"

class GameStatePause : public GameState
{
	private:
	
	sf::View pauseView;
	
	std::map<std::string, Gui> guiSystem;
	
	void resumeGame();
	
	public:
	
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	
	GameStatePause(Game* game);
};

#endif
