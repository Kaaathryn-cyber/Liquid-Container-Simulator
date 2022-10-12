#include <iostream>
#include "Faucet.h"
#include "graph1.h"

Faucet::Faucet() {
	pos.setPoint(0, 0);
	fluid.setStart(pos);
	fluid.setEnd(pos);
}

void Faucet::turnOn() {
	int line;

	line = drawLine(fluid.getStart().getX(), fluid.getStart().getY(), fluid.getEnd().getX(), fluid.getEnd().getY() - 2, 2);
	setColor(line, fluid.getColor().getRed(), fluid.getColor().getGreen(), fluid.getColor().getBlue());
}

void Faucet::turnOff() {
	int line;

	line = drawLine(fluid.getStart().getX(), fluid.getStart().getY(), fluid.getEnd().getX(), fluid.getFillLine() + 3, 2);
	setColor(line, 0, 0, 0);
}

void Faucet::setPosition(GenPoint upper) {
	pos.setPoint(upper.getX(), upper.getY());
}

GenPoint Faucet::getPosition() {
	return pos;
}

void Faucet::setFluid(Fluid fluid) {
	this->fluid = fluid;
}

Fluid Faucet::getFluid() {
	return fluid;
}

void Faucet::draw() {
	//Draw faucet
	displayBMP("faucet.bmp", pos.getX(), pos.getY());
}
