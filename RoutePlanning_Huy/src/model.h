#pragma once  // Means let preprocessor know this header will only be included once 

#include <vector>
#include <unordered_map>
#include <string>
#include <cstddef>

class Model{
    public:
        //Stuct of None includes float x,y coordinate 
        struct Node{
            double x = 0.f;
            double y = 0.f;
        };
        //Struct of Way includes Nodes 
        struct Way{
            std::vector<int> nodes;
        };
        //Struct of Road includes way, type of roads
        struct Road{
            enum Type{Invalid, Unclassified,Service,Residential,Tertiary,
                    Secondary,Primary,Trunk,Motorway,Footway};
            int way;
            Type type;
        };
        //Struct of Railway
        struct Railway{
            int way;
        };
        //Struct of Multipolygon 
        struct Multipolygon{
            std::vector<int> outer;
            std::vector<int> inner;
        };
        struct Building:Multipolygon{};
        struct Leisure:Multipolygon{};
        struct Water:Multipolygon{};
        struct Landuse:Multipolygon{
            enum Type{Invalid,Commercial,Construction,Grass,Forest,Industrial,Railway,Residential};
            Type type;
        };

        //Constructor of Model receives argument as a byte vector of xml 
        //@parameter &xml [vector<std::byte>] bytes of xml representing the world map
        Model(const std::vector<std::byte> &xml);

        //WHAT IS THIS??????
        auto MetricScale() const noexcept {return m_MetricScale;}
        auto &Nodes() const noexcept {return m_Nodes;}
        auto &Ways() const noexcept {return m_Roads;}
        auto &Buildings() const noexcept { return m_Buildings; }
        auto &Leisures() const noexcept { return m_Leisures; }
        auto &Waters() const noexcept { return m_Waters; }
        auto &Landuses() const noexcept { return m_Landuses; }
        auto &Railways() const noexcept { return m_Railways; }

    private:
        void AdjustCoordinates();
        void BuildRings(Multipolygon &mp);
        void LoadData(const std::vector<std::byte> &xml);

        std::vector<Node>m_Nodes;
        std::vector<Way>m_Ways;
        std::vector<Road>m_Roads;
        std::vector<Railway>m_Railways;
        std::vector<Building>m_Buildings;
        std::vector<Leisure>m_Leisures;
        std::vector<Water>m_Waters;
        std::vector<Landuse>m_Landuses;

        double m_MinLat = 0.;
        double m_MaxLat = 0.;
        double m_MinLon = 0.;
        double m_MaxLon = 0.;
        double m_MetricScale = 1.f;
};