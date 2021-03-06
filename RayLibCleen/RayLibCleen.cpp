// RayLibCleen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "raylib.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>


//struct para la forma dinamica
/*struct level {
	std::string title;
	int number;
	int width;
	int height;
	int** background;
	std::string** collisions;
	int** foreground;
};

level* level1;

*/

std::string* textures;
std::string* levels;
std::string* level_length;
std::string* level_height;

int loadTextures(std::ifstream &file, int num)
{
	std::string word;

	textures = new std::string[num + 1];
	textures[0] = "none";
	int counter = 1;
	while (counter < num + 1)
	{
		std::getline(file, word, ';');
		std::getline(file, word, ';');
		textures[counter] = word;
		std::cout << word << std::endl;
		std::getline(file, word, '\n');
		counter++;
	}
	return 0;
}

int loadBackground(std::ifstream &file, int w, int h)
{
	std::string word;
	std::getline(file, word, '\n');

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			std::getline(file, word, ';');
			std::cout << word;
		}
		std::getline(file, word, '\n');
		std::cout << std::endl;
	}

	return 0;
}

int loadForeground(std::ifstream &file, int w, int h)
{
	std::string word;
	std::getline(file, word, '\n');

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			std::getline(file, word, ';');
			std::cout << word;
		}
		std::getline(file, word, '\n');
		std::cout << std::endl;
	}
	return 0;
}

int loadCollisions(std::ifstream &file, int w, int h)
{
	std::string word;

	
	std::getline(file, word, '\n');

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			std::getline(file, word, ';');
			std::cout << word;
		}
		std::getline(file, word, '\n');
		std::cout << std::endl;
	}
	return 0;
}


int loadLevels(std::ifstream &file, int num)
{
	//Esta es la forma dinamica
	/*level1 = new level[num + 1];

	level1->title = "nivelito1";
	level1->number = 1;
	level1->width = 20;
	level1->height = 10;

	level1->background = new int*[level1->width];
	for (int i = 0; i < level1->width; i++)
	{
		level1->background[i] = new int[level1->height];
	}

	level1->collisions = new std::string*[level1->width];
	for (int i = 0; i < level1->width; i++)
	{
		level1->collisions[i] = new std::string[level1->height];
	}

	level1->foreground = new int*[level1->width];
	for (int i = 0; i < level1->width; i++)
	{
		level1->foreground[i] = new int[level1->height];
	}

	level1->background[1][1] = 1;
	level1->collisions[2][3] = "y";
	level1->foreground[5][45] = 2;
	std::cout << level1->background[1][1] << level1->collisions[2][3] << level1->foreground[5][45] << std::endl;

	*/

	std::string word;
	int w = 0;
	int h = 0;

	levels = new std::string[num + 1];
	level_length = new std::string[num + 1];
	level_height = new std::string[num + 1];
	levels[0] = "none";
	level_length[0] = "none";
	level_height[0] = "none";
	int counter = 1;

	while (counter < num + 1)
	{
		std::getline(file, word, ';');
		std::getline(file, word, ';');
		levels[counter] = word;
		std::cout << "Level name : " << word << std::endl;
		std::getline(file, word, ';');
		level_length[counter] = word;
		std::cout << "Level length: " << word << std::endl;
		w = stoi(word);
		std::getline(file, word, ';');
		level_height[counter] = word;
		std::cout << "Level height: " << word << std::endl;
		h = stoi(word);
		std::getline(file, word, '\n');
		std::getline(file, word, ';');
		counter++;

		for (int i = 0; i < 3; i++)
		{
			if (word.compare("BACKGROUND") == 0)
			{
				loadBackground(file, w, h);
			}
			else if (word.compare("FOREGROUND") == 0)
			{
				loadForeground(file, w, h);
			}
			else if (word.compare("COLLISIONS") == 0)
			{
				loadCollisions(file, w, h);
			}
		}
		std::getline(file, word, ';');
	}
	return 0;
}


int main()
{

	/*int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d mode");

	Camera3D camera;
	camera.position = (Vector3) { 10.0f, 10.0f, 10.0f }; // Camera position
	camera.target = (Vector3) { 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                                // Camera field-of-view Y
	camera.type = CAMERA_PERSPECTIVE;                   // Camera mode type

	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

	SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
	

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);

		DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
		DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

		DrawGrid(10, 1.0f);

		EndMode3D();

		DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

		DrawFPS(10, 10);

		EndDrawing();
		
	}

	CloseWindow();
	*/

	std::ifstream map("../RayLibCleen/game.csv");

	if (!map.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << std::endl;
	}

	std::string word;
	std::string title;
	int textures_n = 0;
	int levels_n = 0;



	while (map.good())
	{
		std::getline(map, word, ';');

		if (word.compare("TEXTURES") == 0)
		{
			std::getline(map, word, ';');
			textures_n = std::stoi(word);
			std::getline(map, word, '\n');

			loadTextures(map, textures_n);

		}

		else if (word.compare("TITLE") == 0)
		{
			std::getline(map, title, ';');
			std::cout << title << std::endl;
			std::getline(map, word, '\n');
		}

		else if (word.compare("LEVELS") == 0)
		{
			std::getline(map, word, ';');
			levels_n = std::stoi(word);
			std::getline(map, word, '\n');

			std::cout << "Levels: " << std::endl;
			std::getline(map, word, ';');
			loadLevels(map, levels_n);

		}
	}


	map.close();
}

/*int main()
{
	std::ifstream ip("../RayLibCleen/personas.csv");

	if (!ip.is_open())
		std::cout << "Error al abrir el archivo" << std::endl;

	std::string nombre, apellido, edad, peso;
	int edadI;
	float pesoF;



	while (ip.good())
	{
		std::getline(ip, nombre, ';');
		std::getline(ip, apellido, ';');
		std::getline(ip, edad, ';');
		std::getline(ip, peso, '\n');

		edadI = std::stoi(edad);
		pesoF = std::stof(peso);

		std::cout << "Nombre: " << nombre << " " << apellido << std::endl;
		std::cout << "Edad: " << edadI << std::endl;
		std::cout << "Peso: " << pesoF << std::endl;
		std::cout << "UWU~~~~UWU~~~~UWU~~~~UWU" << std::endl;

	}
	ip.close();
}*/

/*int main(int argc, char* argv[])
{
	std::ofstream archivo;

	archivo.open("datos.csv");

	archivo << "a;b;c;\n";
	archivo << "d;e;f;\n";
	archivo << "1;2;3.456;\n";
	archivo.close();

}*/

