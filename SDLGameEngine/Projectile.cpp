#include "Projectile.h"

Projectile::Projectile(Sprite* sprite, float x, float y, float hsp, float vsp, float liveTime)
	: sprite(sprite), x(x), y(y), hsp(hsp), vsp(vsp), liveTime(liveTime)
{

}

bool Projectile::CheckTimeToDestroy()
{
	currentTime += 0.01f;

	if (currentTime > liveTime)
		return true;
	else
		return false;
}
