/*
3. Splats
Utilizando los sprites correspondientes, realice una aplicación que al hacer click con el botón izquierdo del mouse agregue a la pantalla el círculo rojo y si 
se realiza click con el botón derecho debe añadir el circulo azul.La aplicación debe permitir tener cualquier cantidad de círculos en pantalla.*/

//BIBLIOTECAS//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

//VARIABLES//
Texture tex_redc;
Texture tex_bluec;


int main()
{
	//Cargar texturas
	tex_redc.loadFromFile("rcircle.png");
	tex_bluec.loadFromFile("bcircle.png");

	//Cargar material
	std::vector<sf::Sprite> circulos;

	//Posicion y escalado sprite
	Sprite circulo;

	//Crear ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Splats");
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
			if (evt.type == sf::Event::MouseButtonPressed) {
				if (evt.mouseButton.button == Mouse::Left) {
					circulo.setTexture(tex_redc);
				}
				else if (evt.mouseButton.button == Mouse::Right) {
					circulo.setTexture(tex_bluec);
				}
				sf::Vector2f center = sf::Vector2f(circulo.getLocalBounds().width / 2.f, circulo.getLocalBounds().height / 2.f);
				circulo.setOrigin(center);	
				circulo.setPosition(Mouse::getPosition(App).x, Mouse::getPosition(App).y);
				circulos.push_back(circulo);
			}
		}
		//Limpiar ventana
		App.clear(Color::White);

		//Dibujamos
		for (auto& circulo : circulos) {
			App.draw(circulo);
		}
		
		//Mostrar
		App.display();
	}
	return 0;
}