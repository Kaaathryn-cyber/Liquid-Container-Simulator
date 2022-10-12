#include <iostream>
#include "graph1.h"
#include "Simulation.h"
#include <math.h>

Simulation::Simulation() {
	setFaucet(faucet);
	setContainer(container);
	waterRate = 0;
}

void Simulation::setContainer(Container container) {
	this->container = container;
}

Container Simulation::getContainer() {
	return container;
}

void Simulation::setFaucet(Faucet faucet) {
	this->faucet = faucet;
}

Faucet Simulation::getFaucet() {
	return faucet;
}

int Simulation::getWaterRate() {
	return waterRate;
}

void Simulation::setWaterRate(int waterRate) {
	this->waterRate = waterRate;
}

void Simulation::draw() {
	int wall = 0;
	int ground = 0;
	int pipe;
	int pipeX = 50, pipeY = 50;
	int pipeWidth, pipeHeight = 5;

	//Draw wall and floor
	wall = drawRect(0, 0, 50, 400);
	setColor(wall, 200, 200, 200);

	ground = drawRect(0, 400, 640, 80);
	setColor(ground, 71, 35, 35);

	//Draw container
	
	container.draw();

	//Draw pipe
	
	pipeWidth = faucet.getPosition().getX() - pipeX;

	pipe = drawRect(50, 50, pipeWidth, pipeHeight);
	setColor(pipe, 80, 80, 80);	

	//Draw faucet
	faucet.draw();

	
}

void Simulation::start() {
	int i;
	double deltaH = 0;
	double deltaV = 0;
	int radius = container.getRadius();
	int height = container.getHeight();
	double PI = 3.1415;
	int rect = 0;
	int x = 63, y = 399;

	//Turn on faucet
	faucet.turnOn();

	//Calculate change of height
	deltaV = (3785411.78 * getWaterRate()) / 60.0;

	deltaH = (deltaV / PI) * pow(radius, 2);
	deltaH *= 0.000000001;

	//Fill container
	for (i = 0; i < height / deltaH; i++) {
		rect = drawRect(x, y - deltaH, (radius * 2) - 6, deltaH);
		setColor(rect, faucet.getFluid().getColor().getRed(), faucet.getFluid().getColor().getGreen(), faucet.getFluid().getColor().getBlue());
		y -= deltaH - 1;
		Sleep(100);
		if (y < faucet.getFluid().getFillLine()) {
			break;
		}
	}
	
	//Turn off faucet
	faucet.turnOff();
}