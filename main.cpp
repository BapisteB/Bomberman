 #include "Map.h"

using namespace std;

int main () {
    Map my_map = Map(8);
    Tile my_tile = Tile(true, true, "X");
    my_map.changeTile(0, 0, my_tile);
    my_map.display();
    cout << endl;
    my_map.saveMap("saves/save1.txt");
    Map map2 = Map("saves/save1.txt");
    map2.display();
    return 0;
}