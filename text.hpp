/* 
 * Copyright 2015 Jeffrey L. Sellers
*/

/* This file is part of Jeff's C++ tetris clone.

    Jeff's C++ tetris clone is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Jeff's C++ tetris clone is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Jeff's C++ tetris clone.  If not, see <http://www.gnu.org/licenses/>.
*/ 

#ifndef TEXT_HPP
#define TEXT_HPP

#include <sstream>
#include <SFML/Graphics.hpp>

class Text {
	
	private:
	
		std::string formatString(int convert);
		int lr_increment;
	
	public:
		Text();
		
		sf::RenderWindow window;
		
		std::string toString(int convert);
		sf::Font font;
		void initializeFont();
		
		//Left Panel
		sf::Text score_label;
		sf::Text score_text;
		unsigned int score;
		
		sf::Text lc_label;
		sf::Text lc_text;
		int lines_clear;
		
		
		sf::Text lr_label;
		sf::Text lr_text;
		int lines_remain;
		
		//Right Panel
		sf::Text next_label;
		
		//Level Panel
		sf::Text lvl_label;
		sf::Text lvl_text;
		int level;
		
		//Initialize
		void initializeLeftPanel();
		void initializeRightPanel();

			
		bool update(int lines);
		
		//Get & Set
		void setLevelMetrics(int level);
		int getLevel() {return level;}	
};

#endif

