#include <iostream>
#include <string>
#include "graph1.h"
#include "Faucet.h"
#include "Fluid.h"
#include "GenPoint.h"
#include "Container.h"
#include "Color.h"
#include "Simulation.h"

using namespace std;

int main() {
	//Declare variables
	int waterRate;
	int radius;
	int height;
	int faucetX, faucetY;
	int r = 0, g = 0, b = 0;
	string fluidName;
	int fillLine;

	Faucet faucet;
	Fluid fluid;
	Color color;
	Container container;
	GenPoint pos;
	Simulation simulation;

	//Display Graphics
	displayGraphics();

	//Get Input
	//Get water rate
	do {
		cout << "Enter fluid rate between 1 to 30 gallons/ minute: ";
		cin >> waterRate;

		if (waterRate < 1 || waterRate > 30) {
			cout << "INVALID INPUT!!! Please try again.\n";
		}
	} while (waterRate < 1 || waterRate > 30);

	//Get radius
	do {
		cout << "Enter radius of container <between 10 and 285>: ";
		cin >> radius;

		if (radius < 10 || radius > 285) {
			cout << "INVALID INPUT!!! Please try again.\n";
		}
	} while (radius < 10 || radius > 285);

	//Get height
	do {
		cout << "Enter height of container <between 10 and 300>: ";
		cin >> height;

		if (height < 10 || height > 300) {
			cout << "INVALID INPUT!!! Please try again.\n";
		}
	} while (height < 10 || height > 300);

	//Get RGB value for container
	do {
		cout << "Enter color of container: ";
		cin >> r >> g >> b;

		if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		{
			cout << "INVALID INPUT!!! Please try again.\n";
		}
	} while ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255));

	//Get fluid name
	cout << "Enter fliud name <water, oil, or diesel>: ";
	cin.get();
	getline(cin, fluidName);


	//BUILD FLUID-----------------------------------------
	//start (positioned at the nozle of the faucet)
	pos.setPoint(radius + 50, 67);
	fluid.setStart(pos);

	//end (positioned at the bottom of the container)
	pos.setPoint(radius + 50, 399);
	fluid.setEnd(pos);

	//fillLine (the highest point the fluid can rise/ top y coordinate)
	fillLine = 400 - height;
	fluid.setFillLine(fillLine);

	//fluidName
	fluid.setFluidName(fluidName);

	//----------------------------------------------------

	//BUILD FAUCET----------------------------------------
	//pos (upper left coords for the faucet bmp file)
	faucetY = 12;
	faucetX = (radius - 64) + 57;
	pos.setPoint(faucetX, faucetY);
	faucet.setPosition(pos);

	//fluid (fluid object)
	faucet.setFluid(fluid);
	
	//-----------------------------------------------------
	

	//BUILD CONTAINER--------------------------------------
	//radius
	container.setRadius(radius);

	//height
	container.setHeight(height);

	//pos (upper left coord of container)
	pos.setPoint(60, 400 - height);
	container.setPosition(pos);

	//color color of container
	color.setCol(r, g, b);
	container.setCol(color);
	//-------------------------------------------------------

	//BUILD SIMULATION---------------------------------------
	//faucet (faucet object)
	simulation.setFaucet(faucet);

	//container (container object)
	simulation.setContainer(container);

	//waterRate
	simulation.setWaterRate(waterRate);

	//Draw simulation
	simulation.draw();

	//Start simulation
	simulation.start();
	//--------------------------------------------------------

	return 0;
}