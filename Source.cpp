#include <map>
#include <math.h>

#include "World.h"
#include "TextureHandler.h"
#include "MovementHandler.h"
#include "Painter.h"

#define PI 3.1415926535897932

using namespace std;

float worldSize = 200;
auto world = World(worldSize, worldSize);

bool isDrawingFog = true;
bool isPlayingSound = true;

// walls
Wall mainFloor;
vector<Wall> walls;

auto gdi = GDI();

MovementHandler movementHandler(myNamespace::Point(worldSize - 10, -worldSize + 3, 0));

void ResizeFunction(int worldSize, int height)
{

	const float aspectRatio = (float)worldSize / (float)height;

	glViewport(0, 0, worldSize, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// умножает текущую матрицу на матрицу перспективы.
	glFrustum(-aspectRatio, aspectRatio, -1.0, 1.0, 2.0, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MakeView()
{
	glRotatef(-movementHandler.zRotationAngle, 1, 0, 0);
	glRotatef(-movementHandler.xRotationAngle, 0, 0, 1);

	auto position = movementHandler.GetPosition();

	glTranslatef(-position.x, -position.y, -2);
}

void DisplayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	MakeView();

	Painter::DrawWall(mainFloor);
	Painter::DrawWalls(walls);

	if (!isDrawingFog) Painter::DrawFog(0);
	else Painter::DrawFog();

	glutSwapBuffers();
}

void SpecialFunction(int key, int x, int y)
{
	float speed = 5.f;
	switch (key)
	{
	case GLUT_KEY_UP:
		movementHandler.LookUp();
		break;

	case GLUT_KEY_DOWN:
		movementHandler.LookDown();
		break;

	case GLUT_KEY_RIGHT:
		movementHandler.LookRight();

		break;

	case GLUT_KEY_LEFT:
		movementHandler.LookLeft();
		break;

	case GLUT_KEY_F1:
		if (movementHandler.usingCollision)
		{
			movementHandler.usingCollision = false;
			movementHandler.movementSpeed = 5;
		}
		else
		{
			movementHandler.usingCollision = true;
			movementHandler.movementSpeed = 0.5f;
		}
		break;

	case GLUT_KEY_F2:
		if (isDrawingFog) isDrawingFog = false;
		else isDrawingFog = true;
		break;

	case GLUT_KEY_F3: 
		if (isPlayingSound) 
		{
			isPlayingSound = false;
			PlaySound(nullptr, nullptr, 0);
		}
		else
		{
			isPlayingSound = true;
			PlaySound(L"sounds/background sound.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		}
	}
	glutPostRedisplay();
}

void KeyboardFunction(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w': case 'W':
		movementHandler.MoveForward();
		break;

	case 's': case 'S':
		movementHandler.MoveBackwards();
		break;

	case 'a': case 'A':
		movementHandler.MoveLeft();
		break;

	case 'd': case 'D':
		movementHandler.MoveRight();
		break;

	case 27: // 27 == escape
		exit(0);
		break;
	}
	glutPostRedisplay();
}

void Init()
{
	glEnable(GLUT_MULTISAMPLE);
	glEnable(GL_FOG);
	glEnable(GL_DEPTH_TEST);

	// ¬ключаем режим наложени€ текстуры
	glEnable(GL_TEXTURE_2D);

	UINT floorTexture = TextureHandler::LoadTexture(L"textures/dirt texture.jpg");
	mainFloor = world.GetFloor(floorTexture);

	UINT externalWallsTexture = TextureHandler::LoadTexture(L"textures/white brick wall texture.jpg");
	auto externalWalls = world.GetExternalWalls(externalWallsTexture);

	auto textures = vector<UINT>();

	textures.push_back(TextureHandler::LoadTexture(L"textures/moss wall texture.jpg"));
	textures.push_back(TextureHandler::LoadTexture(L"textures/concrete wall texture.jpg"));
	textures.push_back(TextureHandler::LoadTexture(L"textures/brick wall texture.jpg"));
	textures.push_back(TextureHandler::LoadTexture(L"textures/wooden wall texture.jpg"));
	auto internalWalls = world.GetInternalWalls(textures);

	UINT exitTexture = TextureHandler::LoadTexture(L"textures/exit texture.jpg");
	auto exitWalls = world.GetExit(exitTexture);

	walls.insert(walls.end(), externalWalls.begin(), externalWalls.end());
	walls.insert(walls.end(), internalWalls.begin(), internalWalls.end());
	walls.insert(walls.end(), exitWalls.begin(), exitWalls.end());

	movementHandler.AddWalls(externalWalls);
	movementHandler.AddWalls(internalWalls);

	PlaySound(L"sounds/background sound.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

int oldX = 0, oldY = 0;


void OnMouseMove(int x, int y)
{
	if (oldX - x > 0)  movementHandler.LookLeft();
	else if (oldX - x < 0) movementHandler.LookRight();

	if (oldY - y > 0) movementHandler.LookUp();
	else if (oldY - y < 0) movementHandler.LookDown();

	oldX = x;
	oldY = y;

	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutInitWindowSize(1280, 720);

	glutInitWindowPosition(100, 10);

	glutCreateWindow("Maze");

	glutSetCursor(GLUT_CURSOR_NONE);

	Init();

	glutReshapeFunc(&ResizeFunction);
	glutDisplayFunc(&DisplayFunction);
	glutSpecialFunc(&SpecialFunction);
	glutKeyboardFunc(&KeyboardFunction);

	// todo:
	glutPassiveMotionFunc(&OnMouseMove);

	glutMainLoop();
}