		
#include "BoxCollisionManager.h"

namespace example {
	BoxCollisionManager::BoxCollisionManager()
		{
		}
		BoxCollisionManager::~BoxCollisionManager(){}

		
		void BoxCollisionManager::addStatic(BoxEntity * statics){
			_static.push_back(statics);
		}

		void BoxCollisionManager::addMovable(BoxEntity * movable){
			_movable.push_back(movable);
		}

		 


		BoxCollisionManager::CollisionStats * BoxCollisionManager::checkBoxColision(Box * box, cg::Vector3d oldPos,cg::Vector3d newPos, std::string id){
			CollisionStats * a = new CollisionStats();
			for(int i=0;i < _movable.size();i++){
				BoxEntity * baseEntity = _movable[i];
				if(box->getType()==baseEntity->getbox()->getType()) //Can only be a movable
					continue;

				bool newXCol = linearCollision(box->getMaxX(),newPos[0],baseEntity->getbox()->getMaxX(),baseEntity->getCenter()[0]);
				bool newZCol = linearCollision(box->getMaxZ(),newPos[2],baseEntity->getbox()->getMaxZ(),baseEntity->getCenter()[2]);
				
				if(newXCol && newZCol){
					a->dmg = baseEntity->getDamage();
					a->entType=baseEntity->getbox()->getType();
					bool oldXCol = linearCollision(box->getMaxX(),oldPos[0],baseEntity->getbox()->getMaxX(),baseEntity->getCenter()[0]);
					bool oldZCol = linearCollision(box->getMaxZ(),oldPos[2],baseEntity->getbox()->getMaxZ(),baseEntity->getCenter()[2]);		
					if(oldXCol && oldZCol)
						a->colType = CollisionType::XZ;
					if(oldXCol)
						a->colType = CollisionType::Z;
					else
						a->colType = CollisionType::X;
					return a;
				}

				
			}
			for(int j=0;j < _static.size();j++){
				BoxEntity *baseEntity =_static[j];


				bool newXCol = linearCollision(box->getMaxX(),newPos[0],baseEntity->getbox()->getMaxX(),baseEntity->getCenter()[0]);
				bool newZCol = linearCollision(box->getMaxZ(),newPos[2],baseEntity->getbox()->getMaxZ(),baseEntity->getCenter()[2]);
				
				if(newXCol && newZCol){
					a->dmg = baseEntity->getDamage();
					a->entType=baseEntity->getbox()->getType();
					bool oldXCol = linearCollision(box->getMaxX(),oldPos[0],baseEntity->getbox()->getMaxX(),baseEntity->getCenter()[0]);
					bool oldZCol = linearCollision(box->getMaxZ(),oldPos[2],baseEntity->getbox()->getMaxZ(),baseEntity->getCenter()[2]);		
					//NEEDS TO CHECK Y
					if(oldXCol && oldZCol)
						a->colType = CollisionType::XZ;
					if(oldXCol)
						a->colType = CollisionType::Z;
					else
						a->colType = CollisionType::X;

					if(box->getType() == Box::EntityType::BOX_PLAYER && baseEntity->getbox()->getType()==Box::BOX_KEY){
						baseEntity->playerCollision();
						_static.erase(_static.begin()+j);
						


					}
					return a;
				}

			}
			return NULL;				
		}

		bool BoxCollisionManager::linearCollision(double max, double center, double otherMax,  double otherCenter){
			if(center+max < otherCenter-otherMax){
				return false;
			}
			if(center-max > otherCenter+otherMax){
				return false;
			}
			return true;


		}

}