/*
6. Clickale
Retomando el ejercicio del crosshair ahora realice un videojuego que haga aparecer aleatoriamente en pantalla el Sprite et.png que será nuestro enemigo. El jugador 
utilizando la mira debe clickear sobre los este sprite para que estos desaparezcan. El juego termina cuando el jugador derrota 5 enemigos. Utilice clases para modelar 
los enemigos y el crosshair. Debe escalar las imágenes entregadas para que se puedan ver correctamente
*/

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
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Clickale");
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