/*
2. Drag
Retomando la idea del ejercicio Sniper^4 de la guía anterior, tome ese ejercicio y modifíquelo para que con el mouse se puedan arrastrar dichos puntos cambiándolos de posición.
*/

//BIBLIOTECAS//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

//VARIABLES//
Texture tex_rcircle;
Sprite spr_rcircle1;
Sprite spr_rcircle2;
Sprite spr_rcircle3;
Sprite spr_rcircle4;


int main()
{
	//Cargar texturas
	tex_rcircle.loadFromFile("rcircle.png");

	//Cargar material
	spr_rcircle1.setTexture(tex_rcircle);
	spr_rcircle2.setTexture(tex_rcircle);
	spr_rcircle3.setTexture(tex_rcircle);
	spr_rcircle4.setTexture(tex_rcircle);

	//Crear ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Drag");

	//Posicion y escalado sprite
	sf::Vector2f medidasTextura = sf::Vector2f(tex_rcircle.getSize().x, tex_rcircle.getSize().y);
	sf::Vector2u medidasVentana = App.getSize();
	sf::Vector2f center = sf::Vector2f(spr_rcircle1.getLocalBounds().width / 2.f, spr_rcircle1.getLocalBounds().height / 2.f);
	spr_rcircle1.setOrigin(center);
	spr_rcircle2.setOrigin(center);
	spr_rcircle3.setOrigin(center);
	spr_rcircle4.setOrigin(center);
	spr_rcircle1.setPosition(medidasTextura.x/2,medidasTextura.y/2);
	float posicion2w = medidasVentana.x - medidasTextura.x/2; 
	spr_rcircle2.setPosition(posicion2w, medidasTextura.y/2);
	float posicion3h = medidasVentana.y - medidasTextura.y/2; 
	spr_rcircle3.setPosition(medidasTextura.x/2, posicion3h); 
	spr_rcircle4.setPosition(posicion2w, posicion3h);
	Sprite* sprArrastrando = nullptr;
	
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
			
			FloatRect rc1 = spr_rcircle1.getGlobalBounds();
			FloatRect rc2 = spr_rcircle2.getGlobalBounds();
			FloatRect rc3 = spr_rcircle3.getGlobalBounds();
			FloatRect rc4 = spr_rcircle4.getGlobalBounds();

			if (evt.type == Event::MouseButtonPressed) {
				if (evt.mouseButton.button == Mouse::Left) {

					Vector2i mousePos = Mouse::getPosition(App);
					if (rc1.contains(mousePos.x, mousePos.y))
						sprArrastrando = &spr_rcircle1;
					else if (rc2.contains(mousePos.x, mousePos.y))
						sprArrastrando = &spr_rcircle2;
					else if (rc3.contains(mousePos.x, mousePos.y))
						sprArrastrando = &spr_rcircle3;
					else if (rc4.contains(mousePos.x, mousePos.y))
						sprArrastrando = &spr_rcircle4;
				}
			}
			else if (evt.type == Event::MouseButtonReleased) {
				if (evt.mouseButton.button == Mouse::Left)
					sprArrastrando = nullptr;
			}
		}
		if (sprArrastrando) {
			Vector2i mousePos = Mouse::getPosition(App);
			sprArrastrando->setPosition(mousePos.x, mousePos.y);
		}
		//Limpiar ventana
		App.clear();

		//Dibujamos
		App.draw(spr_rcircle1);
		App.draw(spr_rcircle2);
		App.draw(spr_rcircle3);
		App.draw(spr_rcircle4);

		//Mostrar
		App.display();
	}
	return 0;
}