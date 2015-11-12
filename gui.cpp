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
 
#include <SFML/Graphics.hpp>

#include "gui.hpp"

sf::Vector2f Gui::getSize()
{
	return sf::Vector2f(this->dimensions.x, this->dimensions.y * this->entries.size());
}

int Gui::getEntry(const sf::Vector2f mousePos)
{
	/* If there are no entries then outside of the menu */
	if(entries.size() == 0) return -1;
	if(!this->visible) return -1;
	
	for(int i=0; i< this->entries.size(); ++i)
	{
		/* Translate point to use the tnry's local coordinates. */
		sf::Vector2f point = mousePos;
		point += this->entries[i].shape.getOrigin();
		point -= this->entries[i].shape.getPosition();
		
		if(point.x < 0 || point.x > this->entries[i].shape.getScale().x*this->dimensions.x) continue;
		if(point.y < 0 || point.y > this->entries[i].shape.getScale().y*this->dimensions.y) continue;
		return i;
	}
	
	return -1;
}

void Gui::setEntryText(int entry, std::string text)
{
	if(entry >= entries.size() || entry < 0) return;
	
	entries[entry].text.setString(text);
	
	return;
}

void Gui::setDimensions(sf::Vector2f dimensions)
{
	this->dimensions = dimensions;
	
	for(auto& entry : entries)
	{
		entry.shape.setSize(dimensions);
		entry.text.setCharacterSize(dimensions.y-style.borderSize-padding);
	}
	
	return;
}

void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(!visible) return;
	
	/* Draw each entry of the menu. */
	for(auto entry :  this->entries)
	{
		/* Draw the entry. */
		target.draw(entry.shape);
		target.draw(entry.text);
	}
	
	return;
}

void Gui::show()
{
	sf::Vector2f offset(0.0f, 0.0f);
	
	this->visible = true;
	
	/* Draw each entry of the menu. */
	for(auto& entry : this->entries)
	{
		/* Set the origin of the entry. */
		sf::Vector2f origin = this->getOrigin();
		origin -= offset;
		entry.shape.setOrigin(origin);
		entry.text.setOrigin(origin);
		
		/* Compute the position of the entry. */
		entry.shape.setPosition(this->getPosition());
		entry.text.setPosition(this->getPosition());
		
		if(this->horizontal) offset.x += this->dimensions.x;
		else offset.y += this->dimensions.y;
		
	}
	
	return;	
}

void Gui::hide()
{
	this->visible = false;
	
	return;
}

/* Highlights an entry of the menu. */
void Gui::highlight(const int entry)
{
	for(int i = 0; i < entries.size(); i++)
	{
		if(i == entry)
		{
			entries[i].shape.setFillColor(style.bodyHighlightCol);
			entries[i].shape.setOutlineColor(style.borderHighlightCol);
			entries[i].text.setColor(style.textHighlightCol);
		}
		else
		{
			entries[i].shape.setFillColor(style.bodyCol);
			entries[i].shape.setOutlineColor(style.borderCol);
			entries[i].text.setColor(style.textCol);
		}
	}
	
	return;
}