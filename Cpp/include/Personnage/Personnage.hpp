#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP
#include "BonusMalus/BonusMalus.hpp"
#include "header.hpp"
#include "General.hpp"
#include "Game/Map.hpp"
#include "BombManager.hpp"
class BonusMalus;
class Map;
class Personnage : public sf::Drawable
{
    public:
        Personnage(sf::Vector2f position,const string& str, Map & __map,BombManager & bm);

        virtual ~Personnage();
        void setVitesse(sf::Vector2f vitesse);
        void setnbBombeMax(int nbBombeMax);
        void setnbBombe(int nbBombe);
        void setdegatsBombes(int degatsBombes);
        void setLauncher(bool launcher);
        void setPusher(bool pusher);
        sf::Vector2f getPos();
        sf::Vector2f getVitesse();
        int getnbBombeMax();
        int getnbBombe();
        int getdegatsBombes();
        void addBonusMalus(BonusMalus b);
        void update();
        void moveTo(sf::Vector2f newPos);
        bool canMoveTo(sf::Vector2i newPos);

        sf::FloatRect getHitBox(sf::Vector2f newPos);
        sf::FloatRect getHitBox(sf::Vector2i newPos);
        sf::FloatRect getHitBox();
    protected:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::Vector2f pos, vitesse;
        int nbBombeMax, nbBombe, degatsBombes;
        vector<BonusMalus> bonusMalus;
        vector<Bomb*> _bomb;
        bool launcher, pusher;

        sf::Sprite _sprite;

        int etapePas;
        int direction;
        sf::Clock timerPas;
        sf::Clock deltaUpdate;
        sf::Sprite _sprites[4][9];
        Map & _map;

        BombManager& _bombeManager;

    private:
};

#endif // PERSONNAGE_H
