//BIBLIOTECAS//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

//VARIABLES//


int main()
{
	//Cargar texturas

	//Cargar material

	//Posicion y escalado sprite

	//Crear ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Proyecto");
	//Loop principal
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			switch (evt.type)
			{
			case sf::Event::Closed:
				App.close();
				break;
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