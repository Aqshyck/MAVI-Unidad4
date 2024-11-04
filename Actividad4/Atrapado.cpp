/*
4. Atrapado
Realice una aplicación que coloque el cuadrado representado por el sprite cuad_yellow.png en pantalla. Dicho cuadrado debe poder ser movido con las teclas de 
dirección del teclado. Si se presiona la barra espaciadora el cuadrado debe cambiar a un círculo representado por el Sprite rcircleg.png. Bajo ninguna circunstancia 
la figura puede abandonar la zona visible de pantalla. Ambos sprites deben representarse del mismo tamaño en pantalla.
*/

//BIBLIOTECAS//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

//VARIABLES//
Texture tex_cuadrado;
Texture tex_circulo;
Sprite spr;


int main()
{
	//Crear ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Atrapado");

	//Cargar texturas
	tex_cuadrado.loadFromFile("cuad_yellow.png");
	tex_circulo.loadFromFile("rcircleg.png");

	//Cargar material
	spr.setTexture(tex_cuadrado);

	//Posicion y escalado sprite
	Vector2u medidasVentana = App.getSize();
	Vector2u medidasTextura = tex_cuadrado.getSize();
	Vector2f centro = sf::Vector2f(spr.getLocalBounds().width / 2.f, spr.getLocalBounds().height / 2.f);
	spr.setOrigin(centro);
	spr.setScale(100.f / medidasTextura.x, 100.f / medidasTextura.y);
	spr.setPosition(medidasVentana.x/2,medidasVentana.y/2);

	float movimiento = 5.0f;

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
			if (evt.type == sf::Event::KeyPressed) {
				switch (evt.key.code)
				{
				case sf::Event::Closed:
					App.close();
					break;
				case sf::Keyboard::Left:
					spr.move(-movimiento, 0);
					break;
				case sf::Keyboard::Right:
					spr.move(movimiento, 0);
					break;
				case sf::Keyboard::Up:
					spr.move(0, -movimiento);
					break;
				case sf::Keyboard::Down:
					spr.move(0, movimiento);
					break;
				case sf::Keyboard::Space:
					if (spr.getTexture() == &tex_cuadrado) {
						spr.setTexture(tex_circulo);
					}
					else {
						spr.setTexture(tex_cuadrado);
					}
					break;
				}
			}
		}
		sf::FloatRect limites = spr.getGlobalBounds();
		if (limites.left < 0) {
			spr.setPosition(limites.width/2, spr.getPosition().y);
		}
		if (limites.left + limites.width > App.getSize().x) {
			spr.setPosition(App.getSize().x - limites.width/2, spr.getPosition().y);
		}
		if (limites.top < 0) {
			spr.setPosition(spr.getPosition().x, limites.height/2);
		}
		if (limites.top + limites.height > App.getSize().y) {
			spr.setPosition(spr.getPosition().x, App.getSize().y - limites.height/2);
		}
		//Limpiar ventana
		App.clear();

		//Dibujamos
		App.draw(spr);

		//Mostrar
		App.display();
	}
	return 0;
}