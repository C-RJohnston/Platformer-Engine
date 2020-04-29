#include "Player.h"
#include "Maths.h"


Player::Player()
{
	this->texture.loadFromFile("Graphics/Player.png");
	this->sprite.setTexture(texture);
	this->boundBox = this->sprite.getGlobalBounds();
	this->top = FloatRect(boundBox.left+4, boundBox.top, boundBox.width-4, boundBox.height / 4);
	this->bottom = FloatRect(boundBox.left+4, boundBox.top+boundBox.height*3/4-4, boundBox.width, boundBox.height/4);
	this->left = FloatRect(boundBox.left, boundBox.top+4, boundBox.width/4, boundBox.height-4);
	this->right = FloatRect(boundBox.left + boundBox.width * 3 / 4 + 4, boundBox.top + 2, boundBox.width / 4, boundBox.height - 4);
	this->maxJumpTime = 1.2f;
}

bool Player::spawn(spawnData data)
{
	if (!spawned)
	{
		position = data.startPosition;
		velocity = data.startVelocity;
		gravity = data.gravity;
		spawned = true;
		sprite.setPosition(position);
	}

	return true;
}

void Player::walk(float direction, float dt)
{
	//checks to see if player is running
	if (shift)
	{	//gives the player terminal acceleration
		velocity += acceleration * 1.25f * dt * direction; //factor 1.25 to get up to speed faster when running
		if (abs(velocity.x) > topRunSpeed.x)
		{
			velocity.x = topRunSpeed.x*direction;
		}
	}
	else
	{
		velocity += acceleration * dt * direction;
		if (abs(velocity.x) > topWalkSpeed.x)
		{
			velocity.x = topWalkSpeed.x*direction;
		}
	}

}

void Player::jump(float dt)
{
	if (!this->onGround)
	{
		if (!justJumped) 
		{
			this->timeJumping += dt;
			if (this->timeJumping < this->maxJumpTime)
			{
				this->velocity.y -= gravity.y/2;
			}
			justJumped = true;
		}

	}

}

void Player::setGravity(Vector2f Gravity)
{
	this->gravity = Gravity;
}

Vector2f Player::getCenter()
{
	return Vector2f(
		position.x + sprite.getGlobalBounds().width / 2,
		position.y + sprite.getGlobalBounds().height / 2
	);
}

void Player::stopUp(Vector2f blockPos)
{
	if (abs(velocity.y) > 0.f)
	{
		position.y = blockPos.y + sprite.getGlobalBounds().height;
		velocity.y = 0;
	}
}

void Player::stopDown(Vector2f blockPos)
{
	if (justJumped)
	{
		this->justJumped = false;
		this->timeJumping = 0.f;
	}
	if (abs(velocity.y) > 0.f)
	{
		position.y = blockPos.y - sprite.getGlobalBounds().height;
		velocity.y = 0;
	}
}

void Player::stopLeft(Vector2f blockPos)
{

	if (abs(velocity.x) > 0.f)
	{
		position.x = blockPos.x + sprite.getGlobalBounds().width;
		velocity.x = 0;
	}
}

void Player::stopRight(Vector2f blockPos)
{
	if (abs(velocity.x) > 0.f)
	{
		position.x = blockPos.x - sprite.getGlobalBounds().width;
		velocity.x = 0;
	}
}

void Player::setBools(bool up, bool down)
{
	this->onCeil = up;
	this->onGround = down;
}


void Player::updateBoxes()
{
	this->boundBox = this->sprite.getGlobalBounds();
	this->top = FloatRect(boundBox.left + 4, boundBox.top, boundBox.width - 8, boundBox.height / 4);
	this->bottom = FloatRect(boundBox.left + 4, boundBox.top + boundBox.height * 3 / 4, boundBox.width-8, boundBox.height / 4);
	this->left = FloatRect(boundBox.left, boundBox.top + 4, boundBox.width / 4, boundBox.height - 8);
	this->right = FloatRect(boundBox.left + boundBox.width * 3 / 4, boundBox.top+4, boundBox.width / 4, boundBox.height - 8);
}


void Player::update(float dt)
{
	if (walkLeft)
	{
		this->walk(-1, dt);

	}
	if (walkRight)
	{

		this->walk(1, dt);

	}
	if (jumpUp)
	{
		this->jump(dt);
	}
	//causes the player to slow down
		if (abs(velocity.x) > 0.f)
		{
			velocity += deceleration * dt * (-abs(velocity.x) / velocity.x);
		}
	//causes the player to fall
	if (!onGround)
	{
		velocity += gravity * dt;
	}

	position += velocity * dt;
	sprite.setPosition(position);
	this->updateBoxes();
}

Sprite Player::getSprite()
{
	return this->sprite;
}

//checks for input relevant to play control
void Player::handleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		walkRight = true;
	}
	else
	{
		walkRight = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		walkLeft = true;
	}
	else
	{
		walkLeft = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RShift))
	{
		shift = true;
	}
	else
	{
		shift = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		jumpUp = true;
	}
	else
	{
		jumpUp = false;
	}
}

//returns the binding boxes
FloatRect Player::getBindingBox()
{
	return this->sprite.getGlobalBounds();
}
FloatRect Player::getTopBox()
{
	return this->top;
}
FloatRect Player::getBottomBox()
{
	return this->bottom;
}
FloatRect Player::getLeftBox()
{
	return this->left;
}
FloatRect Player::getRightBox()
{
	return this->right;
}
