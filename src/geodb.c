#include "../include/geodb.h"
#include "../include/geotools.h"
#include <iostream>
#include <fstream>
#include <string>

bool GeoDataBase::load(const std::string& map_data_file) {
    //Attempt to read input from mapdata.txt
    std::ifstream infile("../data/mapdata.txt");

    if ( ! infile) {
        std::cerr << "Error: Cannot open mapdata.txt!" << std::endl;
        return false;
    }
    
    while (true) {
        //Attempt to read in 3 lines
        bool break_loop = false;
        std::string street_name, line2, line3;
        if ( ! std::getline(infile, str_street_name) || 
             ! std::getline(infile, str_coords) || 
             ! std::getline(infile, str_POIS)) 
            break;
        
        std::pair<GeoPoint, GeoPoint> coords = process_coordinates(str_coords);
        m_street_names.insert()

        //Process POIS
        int POIS = (int) str_POIS;

        if (POIS == 0) {
            ...
        }
        else if (POIS > 0)
            midpoint(coords.first, coords.second)
        }
        else { //POIS is a negative number
            std::cerr << "ERROR: POIS is a negative number!" << std::endl;
            return false;
        }




        
        

    }


}

std::pair<GeoPoint, GeoPoint> 
GeoDatabase::process_coordinates(const& std::string line) {
//NOTE: .first must be the start and .second must be the end!
    
}

bool process
