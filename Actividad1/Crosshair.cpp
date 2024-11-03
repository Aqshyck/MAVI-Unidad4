/*
1. Crosshair
Basándose en la practica 3 y los assets entregados, realice una aplicación que abra una ventana y muestre un crosshair en el centro.
*/

//BIBLIOTECAS//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

//VARIABLES//

Texture tex_crosshair;
Sprite spr_crosshair;


int main()
{
	//Cargar texturas
	tex_crosshair.loadFromFile("crosshair.png");

	//Cargar material
	spr_crosshair.setTexture(tex_crosshair);

	//Crear ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Crosshair");

	//Posicion y escalado sprite
	sf::Vector2f center = sf::Vector2f(spr_crosshair.getLocalBounds().width / 2.0f, spr_crosshair.getLocalBounds().height / 2.0f);
	spr_crosshair.setOrigin(center);
		
	// Obtener el ancho y alto de la ventana
	sf::Vector2u windowSize = App.getSize();
	spr_crosshair.setPosition(windowSize.x / 2, windowSize.y / 2);


	//Loop principal
	while (App.isOpen())
	{
		//Limpiar ventana
		App.clear();

		//Dibujamos
		App.draw(spr_crosshair);

		//Mostrar
		App.display();
	}
	return 0;
}