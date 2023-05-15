#include "Painter.h"

void Painter::DrawWall(const Wall& wall)
{
	glColor3f(1, 1, 1);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	auto textureCoordinates = wall.GetTextureCoordinates();
	auto coordinates = wall.GetCoordinates();

	glBindTexture(GL_TEXTURE_2D, wall.GetTextureId());
	glTexCoordPointer(2, GL_FLOAT, 0, &textureCoordinates[0]);

	glVertexPointer(3, GL_FLOAT, 0, &coordinates[0]);
	glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

}

void Painter::DrawWalls(const std::vector<Wall>& walls)
{
	for (auto wall : walls)
		DrawWall(wall);
}

void Painter::DrawFog(float density, float r, float g, float b)
{
	float color[] = { r, g, b };

	glFogi(GL_FOG_MODE, GL_EXP2);
	glFogfv(GL_FOG_COLOR, color);
	glFogf(GL_FOG_DENSITY, density);
	glFogf(GL_FOG_START, 1);
	glFogf(GL_FOG_END, 10);
}
