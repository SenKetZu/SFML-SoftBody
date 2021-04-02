#include <SFML/Graphics.hpp>
#include <iostream>




int main() {


	sf::RenderWindow screen(sf::VideoMode(800, 600), "window", sf::Style::Default);
	sf::CircleShape circulo;
	circulo.setFillColor(sf::Color::Green);
	circulo.setRadius(30);
	
	while (screen.isOpen())
	{
		sf::Event captura;
		while (screen.pollEvent(captura))
		{
			if (captura.type == sf::Event::Closed) {
				screen.close();
			}
		}




		screen.draw(circulo);
		screen.display();
	}
	return 0;
}