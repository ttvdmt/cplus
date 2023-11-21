#include <iostream>
#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Slider
{
private:
	int mProcents;
	bool mIsChosen;
	sf::Vector2f mPosition;
	sf::Vector2f mCore;

public:
	Slider()
	{
		mProcents = 0;
		mIsChosen = false;
		sf::Vector2f mPosition = {0, 0};
		sf::Vector2f mCore = {0, 0};
	}

	Slider(sf::Vector2f position)
	{
		mProcents = 0;
		mIsChosen = false;
		mPosition = position;
		mCore = position;
	}

	int getProcents() const
	{
		return mProcents;
	}

	void draw(sf::RenderWindow& window, sf::Event event)
	{	
		sf::Font font;
		font.loadFromFile("arialmt.ttf");
		std::ostringstream oss;
        oss << mProcents;

		sf::Text text(oss.str(), font, 10); 
		text.move(mCore.x + 120, mCore.y);
		text.setFillColor(sf::Color::White);

		sf::RectangleShape core_rectangle;
		core_rectangle.setFillColor(sf::Color(128, 128, 128));
    	core_rectangle.setPosition(mCore);
    	core_rectangle.setSize({100, 10});

    	sf::RectangleShape add_rectangle;
    	add_rectangle.setFillColor(sf::Color(128, 128, 128));
    	add_rectangle.setPosition({mCore.x + 100, mCore.y});
    	add_rectangle.setSize({10, 10});

    	sf::RectangleShape slider;
		slider.setFillColor(sf::Color(128, 128, 128));
		slider.setOutlineColor(sf::Color::Black);
    	slider.setOutlineThickness(1);
    	slider.setPosition(mPosition);
    	slider.setSize({10, 15});

    	if (event.type == sf::Event::MouseButtonPressed) {
    		sf::Vector2f mousePosition_B = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
    		if (event.mouseButton.button == sf::Mouse::Left) {
    			if (slider.getGlobalBounds().contains(mousePosition_B))
    				mIsChosen = true;

    			else if (core_rectangle.getGlobalBounds().contains(mousePosition_B)) {
    				mPosition = {mousePosition_B.x, slider.getPosition().y};
    				if (mousePosition_B.x - mCore.x > 100)
    					mProcents = 100;
    				else
    					mProcents = mousePosition_B.x - mCore.x;
    			}
    			else
    				mIsChosen = false;
    		}
    	}

    	if (event.type == sf::Event::MouseButtonReleased)
    		mIsChosen = false;

    	if (event.type == sf::Event::MouseMoved) {
    		sf::Vector2f mousePosition_M = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
    		if (mIsChosen) {
    			if (mousePosition_M.x <= mCore.x + 100 && mousePosition_M.x >= mCore.x) {
    				mPosition = {mousePosition_M.x, slider.getPosition().y};
    				mProcents = mousePosition_M.x - mCore.x;
    			}
    			else {
    				if (mousePosition_M.x > mCore.x + 100) {
    					mPosition = {mCore.x + 100, slider.getPosition().y};
    					mProcents = 100;
    				}
    				else if (mousePosition_M.x < mCore.x) {
    					mPosition = {mCore.x, slider.getPosition().y};
    					mProcents = 0;
    				}
    			}
    		}
    	}
    	window.draw(text);
    	window.draw(core_rectangle);
    	window.draw(add_rectangle);
    	window.draw(slider);
	}
};

class Circle
{
private:
	sf::Vector2f mPosition;
	float mRadius;
	sf::Color mColor;

public:
	Circle()
	{
		mPosition = {500, 300};
		mRadius = 50.f;
		mColor = sf::Color(0, 0, 0);
	}

	void draw(sf::RenderWindow& window, int size, int r, int g, int b)
	{
		mColor = sf::Color(r * 255 / 100, g * 255 / 100, b * 255 / 100);
		mRadius = size * 2;

		sf::CircleShape circle(mRadius);
        circle.setFillColor(mColor);
        circle.setOrigin({mRadius, mRadius});
        circle.setPosition(mPosition);
        window.draw(circle);
	}
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Slider");
    window.setFramerateLimit(60);


    Slider size({80, 57});

    Slider R({80, 107});
    Slider G({80, 137});
    Slider B({80, 167});

    Circle circle;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        size.draw(window, event);
        R.draw(window, event);
        G.draw(window, event);
        B.draw(window, event);
        circle.draw(window, size.getProcents(), R.getProcents(), G.getProcents(), B.getProcents());
        window.display();
    }
}