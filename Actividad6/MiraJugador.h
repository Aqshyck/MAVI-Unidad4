#pragma once
#include "Librerias.h"
using namespace sf;

class MiraJugador
{
	Texture tex_mira;
	Sprite spr_mira;

public:
	MiraJugador()
	{
		tex_mira.loadFromFile("crosshair.png");
		spr_mira.setTexture(tex_mira);
		spr_mira.setScale(0.4f, 0.4f);
		Vector2u size = tex_mira.getSize();
		spr_mira.setOrigin(size.x/2.f, size.y / 2.f);

	}
	void Dibujar(RenderWindow* ventana)
	{
		ventana->draw(spr_mira);
	}
	void Posicion(float x, float y) 
	{
		spr_mira.setPosition(x, y);
	}
	Vector2f posicionMira()
	{
		return spr_mira.getPosition();
	}
};
