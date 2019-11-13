#ifndef COORDINATE_H
#define COORDINATE_H


/**
 * \struct Coordinate
 * \brief Stucture pour les coordonnées
 * 
 * Cette structure permet de definir des coordonnées. Il definit une position x et une position y.
 * 
 */
struct Coordinate{
    int x; /*!< coordonnée x */
    int y; /*!< coordonnée y */

    bool operator==(const Coordinate& a) const{
        return (x == a.x && y == a.y);
    }
    
};

#endif