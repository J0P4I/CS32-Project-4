#ifndef GEODB_H
#define GEODB_H

#include <vector>
#include <string>
#include <utility> #for std::pair

#include "base_classes.h"
#include "../include/hashmap.h"

class GeoDatabase: public GeoDatabaseBase 
{ 
public: 
    GeoDatabase(); 
    virtual ~GeoDatabase(); 
 
    virtual bool load(const std::string& map_data_file); 
    virtual bool get_poi_location(const std::string& poi, GeoPoint& point) const; 
    virtual std::vector<GeoPoint> get_connected_points(const GeoPoint& pt) const; 
    virtual std::string get_street_name(const GeoPoint& pt1, const GeoPoint& pt2) const; 

private:
    //Data structure that allows you to search through and find POI's
    HashMap<GeoPoint> m_POIs; //For each POI name, store the geopoint associated with it

    HashMap<GeoPoint> m_connected_POIs //For each Geopoint (by stringified identifier), provide a

    HashMap<std::string> m_street_names //For each 

    //Helper Functions:
    std::pair<GeoPoint, GeoPoint> process_coordinates(const& std::string line);
};

#endif //GEODB_H
