#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace sf
{
	class Shape;
    class Color;
}

class Scene;

class Entity
{
    struct Target 
    {
		sf::Vector2i position;
        float distance;
		bool isSet;
    };

protected:
    sf::CircleShape mShape;
    sf::Vector2f mDirection;
	Target mTarget;
	float mInitialPosX = NULL;
	float mInitialPosY = NULL;
	float mInitialRatioX = NULL;
	float mInitialRatioY = NULL;
    float mSpeed = 0.f;
    bool mToDestroy = false;
    int mTag = -1;
	int mTagTeam = -1;
	bool mHasBall = false;
	bool mRigidBody = false;

public:
	bool GoToDirection(int x, int y, float speed = -1.f);
    bool GoToPosition(int x, int y, float speed = -1.f);
	sf::Vector2f GetInitialPosition() { return {mInitialPosX, mInitialPosY}; }
	sf::Vector2f GetInitialRatio() { return { mInitialRatioX, mInitialRatioY }; }
    void SetPosition(float x, float y, float ratioX = 0.5f, float ratioY = 0.5f);
	void SetDirection(float x, float y, float speed = -1.f);
	void SetSpeed(float speed) { mSpeed = speed; }
	void SetTag(int tag) { mTag = tag; }
	int GetTagTeam() { return mTagTeam; }
	void SetTagTeam(int tagTeam) { mTagTeam = tagTeam; }
	void SetHasBall(bool hasBall) { mHasBall = hasBall; }
	float GetRadius() const { return mShape.getRadius(); }
	void SetRigidBody(bool isRigitBody) { mRigidBody = isRigitBody; }
	bool IsRigidBody() const { return mRigidBody; }
	void ResetTarget() { mTarget.isSet = false; mDirection = sf::Vector2f(0.f, 0.f); }

    sf::Vector2f GetPosition(float ratioX = 0.5f, float ratioY = 0.5f) const;
	sf::Shape* GetShape() { return &mShape; }

	bool IsTag(int tag) const { return mTag == tag; }
	bool IsTagTeam(int tagTeam) const { return mTagTeam == tagTeam; }
    bool IsColliding(Entity* other) const;
	bool IsInside(float x, float y) const;

    void Destroy();
	bool ToDestroy() const { return mToDestroy; }
	
	template<typename T>
	T* GetScene() const;

    Scene* GetScene() const;
	float GetDeltaTime() const;

    template<typename T>
    T* CreateEntity(float radius, const sf::Color& color);

protected:
    Entity() = default;
    ~Entity() = default;

    virtual void OnUpdate() {};
    virtual void OnCollision(Entity* collidedWith) {};
	virtual void OnInitialize() {};
	virtual void OnDestroy() {};
	
private:
    void Update();
	void Initialize(float radius, const sf::Color& color);
	void Repulse(Entity* other);

    friend class GameManager;
    friend Scene;
};

#include "Entity.inl"