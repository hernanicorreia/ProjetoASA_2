#include <iostream>
#include <vector>
#include <sstream>
#include <set>

typedef struct{
    int id;
    std::set<int> line_id;
    std::set<int> conn;
} station;

station create_station(int id){
    station s;
    s.id = id;
    return s;
}


int get_distance(station station, int previous_station, int line_id){

    
}





int main(){
    std::ios::sync_with_stdio(0); // disable sync with c libs
    std::cin.tie(0);              // discard cin buffer after each line of input

    int n_station, n_line, n_conn;
    std::string line;
    std::getline(std::cin, line);
    std::sscanf(line.c_str(), "%d %d %d", &n_station, &n_line, &n_conn);

    station *stations = new station[n_station];
    std::vector<std::set<int>> line_stations(n_line);

    for (int i = 1; i <= n_station; i++)
        stations[i] = create_station(i);
    

    for(int i = 0 ; i < n_conn; i++){
        int station_a, station_b, line_id;
        std::getline(std::cin, line);
        std::sscanf(line.c_str(), "%d %d %d", &station_a, &station_b, &line_id);

        stations[station_a - 1].conn.insert(station_b);
        stations[station_b - 1].conn.insert(station_a);
        stations[station_a - 1].line_id.insert(line_id);
        stations[station_b - 1].line_id.insert(line_id);


        line_stations[line_id - 1].insert(station_a);
        line_stations[line_id - 1].insert(station_b); 
    }



    int *special_stations;
    int n_special_stations = 0;

    for(int i = 0; i < n_line; i++){
        for(int j = 0; j < n_station; j++){
            if(stations[j].line_id.size() == 1 ){
                auto it = stations[j].line_id.begin();
                if (*it == i){
                    special_stations[i] = stations[j].id;
                    n_special_stations++;
                    break;
                }
            }
        }
    }


    int d_max = 0;
    for(int i = 0; i < n_special_stations; i++){
        d_max = get_distance(stations[(special_stations[i] - 1)], 0, *stations[(special_stations[i] - 1)].line_id.begin());
    }
    

}