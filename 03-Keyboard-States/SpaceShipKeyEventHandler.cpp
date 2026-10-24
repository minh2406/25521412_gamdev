#include "SpaceShipKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "SpaceShip.h"

extern SpaceShip* spaceship;
void SpaceShipKeyEventHandler::OnKeyDown(int KeyCode)
{
	if (KeyCode == DIK_SPACE)
	{
		spaceship->fireBullet();
	}
}

void SpaceShipKeyEventHandler::OnKeyUp(int KeyCode)
{

}

void SpaceShipKeyEventHandler::KeyState(BYTE* states)
{
	CGame* game = CGame::GetInstance();

	if(game->IsKeyDown(DIK_RIGHT))
	{
		spaceship->SetState(SPACESHIP_STATE_RIGHT);
	}
	else if(game->IsKeyDown(DIK_LEFT))
	{
		spaceship->SetState(SPACESHIP_STATE_LEFT);
	}
	else if (game->IsKeyDown(DIK_UP))
	{
		spaceship->SetState(SPACESHIP_STATE_UP);
	}
	else if (game->IsKeyDown(DIK_DOWN))
	{
		spaceship->SetState(SPACESHIP_STATE_DOWN);
	}
	else
	{
		spaceship->SetState(SPACESHIP_STATE_FLYING);
	}
}