#include "SpaceShip.h"
#include "SpaceShipNormalState.h"
#include "NormalGunMode.h"
#include "GameEntitiesSingleton.h"
#include "Boss.h"

/*
 *
 */
void SpaceShip::DecreaseLivesAndReset()
{
	pr_Shield = 4;
	pr_Lives -= 1;
	SetPosition(5000, 5000);
}

SpaceShip::SpaceShip() : GameEntities("ship.png"), pr_Speed(300), pr_Shield(4), pr_Cubes(0)
{
	pr_CurrentState = new SpaceShipNormalState;
	pr_CurrentGunMode = new NormalGunMode;
	pr_ForceDirection = new Vector2;
	pr_Lives = 3;
}


SpaceShip::~SpaceShip()
{
	delete pr_CurrentState;
	delete pr_CurrentGunMode;
	delete pr_ForceDirection;
}

/*
 *@brief This function returns the pointer for Force Direction
 *
 *@return Returns the pointer for pr_ForceDirection
 */
Vector2* SpaceShip::GetForceDirection() const
{
	return pr_ForceDirection;
}

/*
 *
 */
float SpaceShip::GetSpeed() const
{
	return pr_Speed;
}


/*
 *@brief This function changes the SpaceShip State to a new one
 *
 *@param The new SpaceShip State to set to
 */
void SpaceShip::SetState(SpaceShipState* ar_NewState)
{
	pr_CurrentState = ar_NewState;
}

/*
 *
 */
void SpaceShip::SetGunMode(GunMode* ar_NewMode)
{
	pr_CurrentGunMode = ar_NewMode;
}

/*
 * @brief This function override the Update function in
 * GameEntities. It updates all the kinematic physics part
 * of the sprite
 *
 * @param ar_DeltaTime The time difference between the current
 * frame and the last frame
 */
void SpaceShip::Update(const float& ar_DeltaTime)
{
	pr_CurrentState->Update(ar_DeltaTime, this);
	if (pr_Cubes == 10)
	{
		GameEntitiesSingleton::GetInstance()->ClearVector();
		auto lo_Boss = new Boss;
		pr_Cubes = 0;
	}
}

/*
 * @brief This function sets the current state to normal state
 */
void SpaceShip::ChangeToNormalState()
{
	pr_CurrentState->ChangeToNormalState(this);
}

/*
 * @brief This function sets the current state to spinning state
 */
void SpaceShip::ChangeToSpinState()
{
	pr_CurrentState->ChangeToSpinState(this);
}

void SpaceShip::ChangeToHookState()
{
	pr_CurrentState->ChangeToHookState(this);
}

/*
 * @brief This function sets the current state to normal state
 */
void SpaceShip::ChangeToNormalMode()
{
	pr_CurrentGunMode->ChangeToNormalMode(this);
}

/*
 *@brief This function sets the current gun mode to hook mode
 */
void SpaceShip::ChangeToHookMode()
{
	pr_CurrentGunMode->ChangeToHookMode(this);
}

/*
 * @brief This function apply force at the direction of the force
 */
void SpaceShip::ApplyForceForward()
{
	pr_CurrentState->ApplyForceForward(this);
}

/*
 *@brief This function apply force at the negative direction
 *of the ship
 */
void SpaceShip::ApplyForceBackward()
{
	pr_CurrentState->ApplyForceBackward(this);
}

/*
 *@brief This function find the normal of the direction, and apply force
 *at that direction.
 *
 *The normal vector is for left direction has a opposite sign for y
 */
void SpaceShip::ApplyForceLeft()
{
	pr_CurrentState->ApplyForceLeft(this);
}

/*
 *@brief This function calls the ApplyForceRight of the current
 *state
 */
void SpaceShip::ApplyForceRight()
{
	pr_CurrentState->ApplyForceRight(this);
}

/*
 *@brief This function calls Rotate Left of the current state
 */
void SpaceShip::RotateLeft()
{
	pr_CurrentState->RotateLeft(this);
}

/*
 *@brief This function calls Rotate Right of the current state
 */
void SpaceShip::RotateRight()
{
	pr_CurrentState->RotateRight(this);
}

/*
 *@brief This functions shoot a bullet. The type of the bullet depends
 *on what gun mode the ship has. The ship can change the gun mode by 
 *getting power ups
 */
void SpaceShip::ShootBullet()
{
	pr_CurrentGunMode->ShootBullets(this);
}

/*
 *
 */
void SpaceShip::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

/*
 *
 */
void SpaceShip::ResolveCollision(SmallAsteroid* ar_SmallAsteroid)
{
	pr_Shield -= 1;
	if (pr_Shield == 0)
		DecreaseLivesAndReset();
}

/*
 *
 */
void SpaceShip::ResolveCollision(BlackHoles* ar_BlackHole)
{
	DecreaseLivesAndReset();
}

void SpaceShip::ResolveCollision(PlannetEnemy* ar_Planet)
{
	DecreaseLivesAndReset();
}

void SpaceShip::ResolveCollision(PowerUps* ar_PowerUp)
{
	unsigned power = (rand() % 5 + 1);
	switch (power)
	{
	case 1:
		ChangeToSpinState();
		break;
	case 2:
		pr_Lives += 1;
		break;
	case 3:
		pr_Shield += 1;
		break;
	case 4:
		ChangeToHookMode();
		break;
	case 5:
		pr_Cubes++;
		break;
	default:
		break;
	}
}

void SpaceShip::ResolveCollision(LargeAsteroid* ar_Asteroid)
{
	pr_Shield -= 2;
	if (pr_Shield == 0)
		DecreaseLivesAndReset();
}

void SpaceShip::ResolveCollision(EnemyBullet* ar_EnemyBullet)
{
	pr_Shield -= 1;
	if (pr_Shield == 0)
		DecreaseLivesAndReset();
}

void SpaceShip::ResolveCollision(KamikazeEnemy* ar_Enemy)
{
	pr_Shield -= 2;
	if (pr_Shield == 0)
		DecreaseLivesAndReset();
}

void SpaceShip::ResolveCollision(ShootingEnemy* ar_Enemy)
{
	pr_Shield -= 2;
	if (pr_Shield == 0)
		DecreaseLivesAndReset();
}
