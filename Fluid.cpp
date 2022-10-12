#include <iostream>
#include "Fluid.h"

Fluid::Fluid() {
	start.setPoint(0, 0);
	end.setPoint(0, 0);
	fillLine = 0;
	fluidName = "";
	
}

void Fluid::setStart(GenPoint start) {
	this->start.setPoint(start.getX(), start.getY());
}

void Fluid::setEnd(GenPoint end) {
	this->end.setPoint(end.getX(), end.getY());
}

void Fluid::setFluidName(string name) {
	fluidName = name;
}

void Fluid::setFillLine(int fillLine) {
	this->fillLine = fillLine;
}

GenPoint Fluid::getStart() {
	return start;
}

GenPoint Fluid::getEnd() {
	return end;
}

int Fluid::getFillLine() {
	return fillLine;
}

Color Fluid::getColor() {

	Color col;

	if (getFluidName() == "water") {
		col.setCol(0, 0, 255);
		return col;
	}
	else if (getFluidName() == "oil") {
		col.setCol(142, 70, 70);
		return col;
	}
	else {
		col.setCol(255, 0, 255);
		return col;
	}
	
}

string Fluid::getFluidName() {
	return fluidName;
}