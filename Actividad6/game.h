#pragma once
#include "Librerias.h"
#include "MiraJugador.h"
#include "Enemigo.h"
using namespace sf;

class game
{
	RenderWindow *ventana;
	MiraJugador *jugador;
	Enemigo* enemigos;
	Text puntaje;
	Font fuente;
	int puntos;

	void actualizarPuntaje()
	{
		char pts[100];
		_itoa_s(puntos, pts, 10);
		puntaje.setString(pts);
	}

public:

	game()
	{
		ventana = new RenderWindow(VideoMode(800, 600), "Clickale");
		jugador = new MiraJugador();
		enemigos = new Enemigo[5];
		puntos = 0;
		fuente.loadFromFile("CHILLER.TTF");
		puntaje.setFont(fuente);
		puntaje.setPosition(0.f, 0.f);
		puntaje.setCharacterSize(20);
		puntaje.setFillColor(Color::Green);
		actualizarPuntaje();
	}
	void run()
	{
		//loop del juego
		while (ventana->isOpen())
		{
			eventos();
			actualizar();
			render();
		}
	}
	void eventos()
	{
		Event evt;
		while (ventana->pollEvent(evt)) {
			switch (evt.type)
			{
			case sf::Event::Closed:
				ventana->close();
				break;
			case sf::Event::MouseMoved:
				jugador->Posicion(evt.mouseMove.x, evt.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Button::Left)
				{
					disparar();
				}
				break;
			}
		}
	}
	void actualizar()
	{
		for (size_t i = 0; i < 5; i++)
		{
			enemigos[i].Actualizar(ventana);
		}
	}
	void disparar()
	{
		Vector2f puntoMira = jugador->posicionMira();
		for (int i=0; i < 5; i++)
		{
			if (enemigos[i].estaActivo())
			{
				if (enemigos[i].EnLaMira(puntoMira.x, puntoMira.y))
				{
					enemigos[i].muerte();
					puntos++;
				}
			}
		}
		actualizarPuntaje();
	}
	void render()
	{
		//limpiar ventana, dibujar
		ventana->clear();
		
		for (int i = 0; i < 5; i++)
		{
			if (enemigos[i].estaActivo())
			{
				enemigos[i].Dibujar(ventana);
			}
		}
		ventana->draw(puntaje);
		jugador->Dibujar(ventana);
		ventana->display();
	}
	~game()
	{
		delete enemigos;
		delete jugador;
		delete ventana;
	}
};
