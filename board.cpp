/* copyright (c) 2017 bourgeois christophe
permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "software"), to deal
in the software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the software, and to permit persons to whom the software is
furnished to do so, subject to the following conditions:
the above copyright notice and this permission notice shall be included in all
copies or substantial portions of the software.
the software is provided "as is", without warranty of any kind, express or
implied, including but not limited to the warranties of merchantability,
fitness for a particular purpose and noninfringement. in no event shall the
authors or copyright holders be liable for any claim, damages or other
lIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.#include "boat.hpp"
*/

#include "board.hpp"

Board::Board()
{
  tileSet.loadFromFile("Ressources/level1.png");
  tile.setTexture(tileSet);
  width = 10;
  height = 16;
  tileSize = 32;
}


std::vector<int>& Board::load()
{
  int tmp(0);
  
  std::ifstream level("Ressources/map.txt");
  
  if(level.is_open()) {
    while(level >> tmp){ map.push_back(tmp); }
    
  }

  return map;
}

bool once(false);

void  Board::show(sf::RenderWindow &win)
{
  int nTile(0); 
  int n(0);

  // load Tileset and show map
  for(int y(0);y < height;y++) {
    for(int x(0); x < width; x++) {
      nTile = map[n++];
      tileX = nTile % (tileSet.getSize().x / tileSize);
      tileY = nTile / (tileSet.getSize().x / tileSize);
      
      tile.setTextureRect(sf::IntRect(tileX * tileSize,tileY * tileSize,tileSize,tileSize));
      tile.setPosition(x * tileSize, y * tileSize);
      
      win.draw(tile);
   
    }
   }
}


std::vector<sf::FloatRect> Board::collisionInfo()
{
  int i(0);
   for(int y(0);y < height;y++) {
    for(int x(0); x < width; x++) {
      if(map[i++] == 3)
	  {
	  blocks.push_back(sf::FloatRect(x * tileSize, y * tileSize,tileSize,tileSize));
	  }
	 }
	}	
   
   return blocks;
}
