#pragma once
#include "Librerias.h"
using namespace sf;

class Enemigo
{
	Texture tex_et;
	Sprite spr_enemigo;
	bool conVida;
	bool estaVisible;
	sf::Clock reloj;
	float tiempoEnPantalla;
	float tiempoFuera;

	Vector2f randomPos(Vector2u maxPos) 
	{
		Vector2f random((float)(rand() % maxPos.x), (float)(rand() % maxPos.y));
		return random;
	}

public:
	Vector2f velocidad;

	Enemigo()
	{
		tex_et.loadFromFile("et.png");
		spr_enemigo.setTexture(tex_et);
		spr_enemigo.setScale(0.05f, 0.05f);
		conVida = true;
		estaVisible = false;
		tiempoEnPantalla = 0.8f;
		tiempoFuera = 0.5f;
	}

	bool estaVivo()
	{
		return conVida;
	}
	bool estaActivo()
	{
		return conVida && estaVisible;
	}
	bool EnLaMira(float x, float y)
	{
		FloatRect bounds = spr_enemigo.getGlobalBounds();
		return bounds.contains(x, y);
	}
	void muerte()
	{
		conVida = false;
	}
	void Dibujar(RenderWindow *ventana)
	{
		ventana->draw(spr_enemigo);
	}
	void Actualizar(RenderWindow* ventana)
	{
		if (!conVida)
		{
			return;
		}
		if (!estaVisible)
		{
			if (reloj.getElapsedTime().asSeconds() > tiempoFuera)
			{
				reloj.restart();
				if (rand() % 100 < 25)
				{
					estaVisible = true;
					spr_enemigo.setPosition(randomPos(ventana->getSize()));
				}
			}
		}
		else
		{
			if (reloj.getElapsedTime().asSeconds()  > tiempoEnPantalla)
			{
				estaVisible = false;
				reloj.restart();
			}
		}
	}
};
