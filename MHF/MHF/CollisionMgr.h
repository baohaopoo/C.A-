#pragma once

class Object;

class CollisionMgr
{
public:
	CollisionMgr();
	~CollisionMgr();

public:
	static bool checkSphereCollision(Object* dst, Object* src);
public:
	static void CollisionRect(list<Object*>& dst, list<Object*>& src);
	static void CollisionShpere(list<Object*>& dst, list<Object*>&src);
	static void CollisionObject(list<Object*>& dst, list<Object*>&src);
	static bool Check_Rect(Object* pDest, Object* pSrc, float* _pX, float* _pY);
};

