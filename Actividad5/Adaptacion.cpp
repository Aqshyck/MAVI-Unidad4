/*
5. Adaptación
Investigue e implemente una aplicación que permita al usuario cambiar el tamaño de la ventana, pero que el mismo no pueda ser menor a 100x100 ni mayor a 1000x1000.
*/

//BIBLIOTECAS//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

//VARIABLES//


int main()
{	
	//Crear ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Adaptacion");

	//Limites de tamaño de ventana
	unsigned int tamanoMinimo = 100;
	unsigned int tamanoMaximo = 1000;
			
	//Loop principal
	while (App.isOpen())
	{
		sf::Event evt;
		while (App.pollEvent(evt)) {
			switch (evt.type)
			{
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::Resized:
				sf::Vector2u nuevoTamano(evt.size.width, evt.size.height);
				nuevoTamano.x = std::max(tamanoMinimo, std::min(tamanoMaximo, nuevoTamano.x));
				nuevoTamano.y = std::max(tamanoMinimo, std::min(tamanoMaximo, nuevoTamano.y));

				App.setSize(nuevoTamano);
			}
		}
		//Limpiar ventana
		App.clear();

		//Dibujamos
		//App.draw();

		//Mostrar
		App.display();
	}
	return 0;
}