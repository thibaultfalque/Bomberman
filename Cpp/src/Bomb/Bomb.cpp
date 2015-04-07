#include "Bomb/Bomb.hpp"
#include "Personnage.hpp"
Bomb::Bomb(Personnage & p, int puissance):owner(&p)
{
    _personnageOut = false;
    position=owner->getPos();
    textureName="bombeP"+to_string(owner->getType())+".png";
    sprite=Ressource::getSprite(textureName,IntRect(0,0,LARGEUR,HAUTEUR));
    sprite.setPosition(position);
    power=puissance;
    stratBomb=new StratBombSimple();
    _explosion=false;

    tempTotal=0;


}
Bomb::Bomb(sf::Vector2i& mapPosition){
    stratBomb=new StratBombSimple();
    mapPosition=mapPosition;
}

void Bomb::update(sf::Time tps){
    tempTotal+=tps.asMilliseconds();
    if(_explosion)
        return;

    else if(tempTotal>2250 && !_explosion){
        _explosion=true;
        tempTotal=0;
    }

    else if(tempTotal>2000 && !_explosion){
        sprite=Ressource::getSprite(textureName,IntRect(LARGEUR*2,0,LARGEUR,HAUTEUR));
        sprite.setPosition(position);

    }
    else if(tempTotal>1000 && !_explosion){
        sprite=Ressource::getSprite(textureName,IntRect(LARGEUR,0,LARGEUR,HAUTEUR));
        sprite.setPosition(position);
    }

    if(!_personnageOut){
        _personnageOut=!owner->getHitBox().intersects(sprite.getGlobalBounds());
    }

}
bool Bomb::mustExplode(){
    return _explosion;
}
void Bomb::getListCaseTouch(Map& m,vector<vector<bool>>& tab){
    stratBomb->getCaseTouch(m,tab,*this);
}
void Bomb::explode(Map& m){
    stratBomb->explode(m,*this);
    _explosion=false;
}
void Bomb::setMapPosition(const sf::Vector2i& mapPosition){
    _mapPosition=mapPosition;
}
sf::Vector2i& Bomb::getMapPosition(){
    return _mapPosition;
}
void Bomb::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(sprite,states);
}
void Bomb::setPosition(const sf::Vector2f& pos){
    position=pos;
    sprite.setPosition(pos);
}
int Bomb::getPower(){
    return power;
}
Personnage * Bomb::getPersonnage(){
    return owner;
}

bool Bomb::getPersonnageOut(){
    return _personnageOut;
}

Bomb::~Bomb()
{
    //dtor
}
